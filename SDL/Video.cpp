// Part of SimCoupe - A SAM Coupe emulator
//
// Video.cpp: SDL video handling for surfaces, screen modes, palettes etc.
//
//  Copyright (c) 1999-2010  Simon Owen
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

//  ToDo:
//   - possibly separate out the OpenGL and SDL code further?

#include "SimCoupe.h"
#include "Video.h"

#include "Action.h"
#include "Display.h"
#include "Frame.h"
#include "GUI.h"
#include "Options.h"
#include "UI.h"

const int N_TOTAL_COLOURS = N_PALETTE_COLOURS + N_GUI_COLOURS;

// SAM RGB values in appropriate format, and YUV values pre-shifted for overlay surface
DWORD aulPalette[N_TOTAL_COLOURS], aulScanline[N_TOTAL_COLOURS];

SDL_Surface *pBack, *pFront, *pIcon;


// Mask for the current SimCoupe.bmp image used as the SDL program icon
static Uint8 abIconMask[128] =
{
    0x00, 0x01, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x00,
    0x00, 0x1f, 0xf0, 0x00, 0x00, 0x7f, 0xfc, 0x00,
    0x00, 0xff, 0xfe, 0x00, 0x01, 0xff, 0xff, 0x00,
    0x03, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0x80,
    0x07, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xc0,
    0x07, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xc0,
    0x07, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xc0,
    0x28, 0x1f, 0xf0, 0x28, 0x7c, 0x7d, 0xdc, 0x7c,
    0xfc, 0xff, 0xfe, 0x7e, 0x7f, 0xff, 0xff, 0xfc,
    0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xfc,
    0x03, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0x80,
    0x07, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xc0,
    0x07, 0xff, 0xff, 0xc0, 0x07, 0xff, 0xff, 0xc0,
    0x00, 0xf8, 0x3e, 0x00, 0x01, 0xfc, 0x7f, 0x00,
    0x03, 0xfe, 0xff, 0x80, 0x03, 0xfe, 0xff, 0x80,
    0x03, 0xfe, 0xff, 0x80, 0x03, 0xfe, 0xff, 0x80
};


#ifdef USE_OPENGL

GLuint dlist;
GLuint auTextures[N_TEXTURES+1];
DWORD dwTextureData[N_TEXTURES+1][256][256];
GLenum g_glPixelFormat, g_glDataType;


void glBork (const char* pcsz_)
{
    GLenum error = glGetError();
    if (error != GL_NO_ERROR)
    {
        char szError[64];
        sprintf(szError, "%s: %#04x", pcsz_, (UINT)error);
#ifdef _WINDOWS
        MessageBox(NULL, szError, "glBork", MB_ICONSTOP);
#else
        fprintf(stderr, "%s\n", szError);
#endif
        exit(0);
    }
}

void InitGL ()
{
    int nWidth = Frame::GetWidth(), nHeight = Frame::GetHeight();
    int nW = GetOption(ratio5_4) ? nWidth * 5/4 : nWidth;
    int i;

    if (!GetOption(stretchtofit))
    {
        // Centralise what we have without any scaling
        int nX = (pFront->w-nW)>>1, nY = (pFront->h-nHeight)>>2;
        rTarget.x = nX, rTarget.y = nY, rTarget.w = nW, rTarget.h = nHeight;
    }
    else
    {
        // Calculate the scaled widths/heights and positions we might need
        int nW2 = nW * pFront->h / nHeight, nH2 = nHeight * pFront->w / nW;
        int nX = (pFront->w-nW2)>>1, nY = (pFront->h-nH2)>>1;

        // Scale to fill the width or the height, depending on which fits best
        if (nH2 > pFront->h)
            rTarget.x = nX, rTarget.y = 0, rTarget.w = nW2, rTarget.h = pFront->h;
        else
            rTarget.x = 0, rTarget.y = nY, rTarget.w = pFront->w, rTarget.h = nH2;
    }

    // Set up a pixel units to avoid messing about when calculating positioning
    // Hack: offset down by 1 pixel to stop the GUI half bleeding into the bottom line of the emulation view!
    glViewport(rTarget.x, rTarget.y-1, rTarget.w, rTarget.h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,nWidth,0,nHeight,-1,1);


    // 16-bit packed pixel support halves the amount of data to move around
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    // The first is PowerPC-only, as it's slow on Intel Mac Minis [Andrew Collier]
    if (glExtension("GL_APPLE_packed_pixel") && glExtension("GL_EXT_bgra"))
        g_glPixelFormat = GL_BGRA_EXT, g_glDataType = GL_UNSIGNED_SHORT_1_5_5_5_REV;
    else
#endif

    // This is a fairly safe choice that should work well on most systems
    if (glExtension("GL_EXT_packed_pixels"))
        g_glPixelFormat = GL_RGBA, g_glDataType = GL_UNSIGNED_SHORT_5_5_5_1_EXT;

    // Otherwise fall back on plain 32-bit RGBA
    else
        g_glPixelFormat = GL_RGBA, g_glDataType = GL_UNSIGNED_BYTE;

    // Store Mac textures locally if possible for an AGP transfer boost
    // Note: do this for ATI cards only at present, as both nVidia and Intel seems to suffer a performance hit
    if (glExtension("GL_APPLE_client_storage") && !memcmp(glGetString(GL_RENDERER), "ATI", 3))
        glPixelStorei(GL_UNPACK_CLIENT_STORAGE_APPLE, GL_TRUE);

    // Try for edge-clamped textures, to avoid visible seams between filtered tiles (mainly OS X)
    GLuint uClamp = glExtension("GL_SGIS_texture_edge_clamp") ? GL_CLAMP_TO_EDGE : GL_CLAMP;


    glEnable(GL_TEXTURE_2D);
    glGenTextures(N_TEXTURES+1,auTextures);

    for (i = 0 ; i < N_TEXTURES ; i++)
    {
        // Use linear filtering if manually enabled, or we're in 5:4 mode
        GLuint uFilter = (GetOption(filter) || GetOption(ratio5_4)) ? GL_LINEAR:GL_NEAREST;

        glBindTexture(GL_TEXTURE_2D, auTextures[i]);

        // Set the clamping and filtering texture parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, uClamp);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, uClamp);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, uFilter);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, uFilter);

        // Create the 256x256 texture tile
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 256, 256, 0, g_glPixelFormat, g_glDataType, dwTextureData[i]);
        glBork("glTexImage2D");
    }

    
    // Build the scanline intensity pixel, and merge in the endian-specific alpha channel
    Uint32 ulScanline = (GetOption(scanlevel) * 0xff / 100) * 0x00010101;
#if SDL_BYTEORDER == SDL_LIL_ENDIAN
    ulScanline |= 0xff000000;
#else
    ulScanline = (ulScanline << 8) | 0x000000ff;
#endif

    // Fill the scanline texture
    for (i = 0 ; i < 256 ; i += 2)
    {
        for (int j = 0 ; j < 256 ; j++)
        {
            dwTextureData[N_TEXTURES][i][j] = ulScanline;
            dwTextureData[N_TEXTURES][i+1][j] = 0xffffffff;
        }
    }

    glBindTexture(GL_TEXTURE_2D, auTextures[N_TEXTURES]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, uClamp);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, uClamp);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GetOption(filter)?GL_LINEAR:GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GetOption(filter)?GL_LINEAR:GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 256, 256, 0, GL_RGBA, GL_UNSIGNED_BYTE, dwTextureData[N_TEXTURES]);

    dlist = glGenLists(1);
    glNewList(dlist,GL_COMPILE);

    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    glClear(GL_COLOR_BUFFER_BIT);

    for (int yy = 0 ; yy < (N_TEXTURES/3) ; yy++)
    {
        for (int xx = 0 ; xx < 3 ; xx++)
        {
            int nSize = 1 << 8, nX = xx << 8, nY = yy << 8;

            glBindTexture(GL_TEXTURE_2D, auTextures[3*yy + xx]);

            glBegin(GL_QUADS);
            glTexCoord2i(0,1); glVertex2i(nX,       nY+nSize);
            glTexCoord2i(0,0); glVertex2i(nX,       nY);
            glTexCoord2i(1,0); glVertex2i(nX+nSize, nY);
            glTexCoord2i(1,1); glVertex2i(nX+nSize, nY+nSize);
            glEnd();
        }
    }

    glEndList();
}

void ExitGL ()
{
    // Clean up the display list and textures
    if (dlist) { glDeleteLists(dlist, 1); dlist = 0; }
    if (auTextures[0]) glDeleteTextures(N_TEXTURES+1,auTextures);
}

#endif

// function to initialize DirectDraw in windowed mode
bool Video::Init (bool fFirstInit_/*=false*/)
{
    bool fRet = false;

    Exit(true);
    TRACE("-> Video::Init(%s)\n", fFirstInit_ ? "first" : "");

    if (fFirstInit_ && SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
        TRACE("SDL_InitSubSystem(SDL_INIT_VIDEO) failed: %s: %s\n", SDL_GetError());
    else
    {
        SDL_WM_SetIcon(pIcon = SDL_LoadBMP(OSD::GetFilePath("SimCoupe.bmp")), abIconMask);

        DWORD dwWidth = Frame::GetWidth(), dwHeight = Frame::GetHeight();

#ifdef USE_OPENGL
        // In 5:4 mode we'll stretch the viewing surfaces by 25%
        if (GetOption(ratio5_4))
            dwWidth = (dwWidth * 5) >> 2;
#endif
        // Use 16-bit for fullscreen or the current desktop depth
        int nDepth = GetOption(fullscreen) ? 16 : 0;

        // Use a hardware surface if possible, and a palette if we're running in 8-bit mode
        DWORD dwOptions =  SDL_HWSURFACE | (nDepth == 8) ? SDL_HWPALETTE : 0;

#ifdef USE_OPENGL
            SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

            if (GetOption(fullscreen))
            {
                dwOptions |= SDL_FULLSCREEN;
                nDepth = 32;
            }

            if (!(pFront = SDL_SetVideoMode(dwWidth, dwHeight, nDepth, (dwOptions | SDL_HWSURFACE | SDL_OPENGL))))
            {
                char sz[128];
                sprintf(sz, "SDL_SetVideoMode() failed: %s", SDL_GetError());
                UI::ShowMessage(msgFatal, sz);
            }

            InitGL();
            CreatePalettes();
            fRet = UI::Init(fFirstInit_);
#else
        // Full screen mode requires a display mode change
        if (!GetOption(fullscreen))
            pFront = SDL_SetVideoMode(dwWidth, dwHeight, nDepth, dwOptions);
        else
        {
            int nWidth, nHeight;

            // Work out the best-fit mode for the visible frame area
            if (dwWidth <= 640 && dwHeight <= 480)
                nWidth = 640, nHeight = 480;
            else if (dwWidth <= 800 && dwHeight <= 600)
                nWidth = 800, nHeight = 600;
            else
                nWidth = 1024, nHeight = 768;

            // Set the video mode, or keep reducing the requirements until we find one
            while (!(pFront = SDL_SetVideoMode(nWidth, nHeight, nDepth, SDL_FULLSCREEN | dwOptions)))
            {
                TRACE("!!! Failed to set %dx%dx%d mode: %s\n", nWidth, nHeight, nDepth, SDL_GetError());

                // If we're already on the lowest depth, try lower resolutions
                if (nDepth == 8)
                {
                    if (nHeight == 768)
                        nWidth = 800, nHeight = 600;
                    else if (nHeight == 600)
                        nWidth = 640, nHeight = 480;
                    else if (nHeight == 480)
                    {
                        TRACE("SDL_SetVideoMode() failed with ALL modes!\n");
                        return false;
                    }
                }

                // Fall back to a lower depth
                else if (nDepth == 24)
                    nDepth = 16;
                else
                    nDepth >>= 1;
            }
        }

        // Did we fail to create the front buffer?
        if (!pFront)
            TRACE("Failed to create front buffer!\n");

        // Create a back buffer in the same format as the front
        else if (!(pBack = SDL_CreateRGBSurface(dwOptions, dwWidth, dwHeight, pFront->format->BitsPerPixel,
                pFront->format->Rmask, pFront->format->Gmask, pFront->format->Bmask, pFront->format->Amask)))
            TRACE("Can't create back buffer: %s\n", SDL_GetError());
        else
        {
            // Clear out any garbage from the back surface
            SDL_FillRect(pBack, NULL, 0);

            // Create the appropriate palette needed for the surface (including a hardware palette for 8-bit mode)
            CreatePalettes();

            fRet = UI::Init(fFirstInit_);
        }
#endif
    }

    if (!fRet)
        Exit();

    TRACE("<- Video::Init() returning %s\n", fRet ? "true" : "FALSE");
    return fRet;
}

// Cleanup DirectX by releasing all the interfaces we have
void Video::Exit (bool fReInit_/*=false*/)
{
    TRACE("-> Video::Exit(%s)\n", fReInit_ ? "reinit" : "");

#ifdef USE_OPENGL
    ExitGL();
#endif

    if (pBack) { SDL_FreeSurface(pBack); pBack = NULL; }
    if (pFront) { SDL_FreeSurface(pFront); pFront = NULL; }
    if (pIcon) { SDL_FreeSurface(pIcon); pIcon = NULL; }

    if (!fReInit_)
        SDL_QuitSubSystem(SDL_INIT_VIDEO);

    TRACE("<- Video::Exit()\n");
}


// Create whatever's needed for actually displaying the SAM image
bool Video::CreatePalettes (bool fDimmed_)
{
    SDL_Color acPalette[N_TOTAL_COLOURS];
    bool fPalette = pBack && (pBack->format->BitsPerPixel == 8);
    TRACE("CreatePalette: fPalette = %s\n", fPalette ? "true" : "false");

    // Determine the scanline brightness level adjustment, in the range -100 to +100
    int nScanAdjust = GetOption(scanlines) ? (GetOption(scanlevel) - 100) : 0;
    if (nScanAdjust < -100) nScanAdjust = -100;

    fDimmed_ |= (g_fPaused && !g_fFrameStep) || GUI::IsActive() || (!g_fActive && GetOption(pauseinactive));
    const RGBA *pSAM = IO::GetPalette(fDimmed_), *pGUI = GUI::GetPalette();

    // Build the full palette from SAM and GUI colours
    for (int i = 0; i < N_TOTAL_COLOURS ; i++)
    {
        // Look up the colour in the appropriate palette
        const RGBA* p = (i < N_PALETTE_COLOURS) ? &pSAM[i] : &pGUI[i-N_PALETTE_COLOURS];
        BYTE r = p->bRed, g = p->bGreen, b = p->bBlue;

#ifdef USE_OPENGL
        // We don't currently use alpha, but pick it up to allow for future translucent windows
        BYTE a = p->bAlpha;

        // 32-bit RGBA?
        if (g_glDataType == GL_UNSIGNED_BYTE)
        {
#if SDL_BYTEORDER == SDL_LIL_ENDIAN
            aulPalette[i] = (a << 24) | (b << 16) | (g << 8) | r;
            AdjustBrightness(r,g,b, nScanAdjust);
            aulScanline[i] = (a << 24) | (b << 16) | (g << 8) | r;
#else
            aulPalette[i] = (r << 24) | (g << 16) | (b << 8) | a;
            AdjustBrightness(r,g,b, nScanAdjust);
            aulScanline[i] = (r << 24) | (g << 16) | (b << 8) | a;
#endif
        }
        else    // high-colour OpenGL
        {
            DWORD dwRMask, dwGMask, dwBMask, dwAMask;

            // The component masks depend on the data type
            if (g_glDataType == GL_UNSIGNED_SHORT_5_5_5_1_EXT)
                dwRMask = 0xf800, dwGMask = 0x07c0, dwBMask = 0x003e, dwAMask = 0x0001;
            else
                dwAMask = 0x8000, dwRMask = 0x7c00, dwGMask = 0x03e0, dwBMask = 0x001f;

            // Set the normal pixel
            aulPalette[i] = RGB2Native(r,g,b,a, dwRMask,dwGMask,dwBMask,dwAMask);

            // Set the scanline pixel
            AdjustBrightness(r,g,b, nScanAdjust);
            aulScanline[i] = RGB2Native(r,g,b,a, dwRMask,dwGMask,dwBMask,dwAMask);
        }
#else
        // Ask SDL to map non-palettised colours
        if (!fPalette)
        {
            aulPalette[i] = SDL_MapRGB(pBack->format, r,g,b);
            AdjustBrightness(r,g,b, nScanAdjust);
            aulScanline[i] = SDL_MapRGB(pBack->format, r,g,b);
        }
        else
        {
            // Set the palette index and components
            aulPalette[i] = aulScanline[i] = i;
            acPalette[i].r = r;
            acPalette[i].g = g;
            acPalette[i].b = b;
        }
#endif
    }

    // If a palette is required, set it on both surfaces now
    if (fPalette)
    {
        SDL_SetPalette(pBack,  SDL_LOGPAL, acPalette, 0, N_TOTAL_COLOURS);
        SDL_SetPalette(pFront, SDL_LOGPAL|SDL_PHYSPAL, acPalette, 0, N_TOTAL_COLOURS);
    }

    // Because the pixel format may have changed, we need to refresh the SAM CLUT pixel values
    for (int c = 0 ; c < 16 ; c++)
        clut[c] = aulPalette[clutval[c]];

    // Ensure the display is redrawn to reflect the changes
    Display::SetDirty();

    return true;
}
