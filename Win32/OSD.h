// Part of SimCoupe - A SAM Coupe emulator
//
// OSD.h: Win32 common OS-dependant functions
//
//  Copyright (c) 1999-2004  Simon Owen
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

#ifndef OSD_H
#define OSD_H


// disable stupid 'debug symbols being truncated' warning
#pragma warning(disable:4786)

// Reverse the _s warnings that Microsoft forces on us
#ifndef __USE_SECURE_LIB__
#define _CRT_SECURE_NO_DEPRECATE
#endif

#define STRICT
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <mmsystem.h>   // for timeSetEvent
#include <sys\types.h>  // for _off_t etc.
#include <direct.h>     // for _mkdir
#include <stdio.h>      // for FILE structure
#include <winioctl.h>   // for DISK_GEOMETRY and IOCTL_DISK_GET_DRIVE_GEOMETRY
#include <commctrl.h>	// for Windows common controls

#pragma include_alias(<io.h>, <..\Include\IO.h>)
#include <io.h>

#ifdef USE_ZLIB
#pragma comment(lib, "zlib1")   // new 1.2.x version, required to avoid zlib binary mismatch problems
#endif

#ifdef USE_SAASOUND
#pragma comment(lib, "SAASound")
#endif


// For NT4 compatability we only use DX3 features, except for input which requires DX5
#define DIRECTDRAW_VERSION      0x0300
#define DIRECT3D_VERSION        0x0300
#define DIRECTSOUND_VERSION     0x0300
#define DIRECTINPUT_VERSION     0x0500  // we'll do a run-time check for DX5 before using it

#include <dsound.h>
#include <ddraw.h>

// Make sure the DX5 (or higher) SDK was found
#ifndef DSBLOCK_ENTIREBUFFER
#error DX5 (or higher) SDK is required to build SimCoupe
#endif


#define PATH_SEPARATOR          '\\'

#define strcasecmp  _strcmpi
#define mkdir(p,m)  _mkdir(p)

#define R_OK        4
#define W_OK        2
#define X_OK        1
#define F_OK        0

#define access(p,m)      _access((p),(m)&(R_OK|W_OK))

#define _S_ISTYPE(mode,mask)    (((mode) & _S_IFMT) == (mask))
#define S_ISDIR(mode)           _S_ISTYPE((mode), _S_IFDIR)
#define S_ISREG(mode)           _S_ISTYPE((mode), _S_IFREG)
#define S_ISBLK(mode)           0
#define S_ISLNK(mode)           0

#ifndef MAXLONG_PTR
typedef long    LONG_PTR;       // Needed for VC6 to compile out 64-bit compatible code
#endif


// Windows lacks direct.h, so we'll supply our own
struct dirent
{
    long            d_ino;
    _off_t          d_off;
    unsigned short  d_reclen;
    char            d_name[256];
};

typedef void* DIR;

DIR* opendir (const char* pcszDir_);
struct dirent* readdir (DIR* hDir_);
int closedir (DIR* hDir_);

////////////////////////////////////////////////////////////////////////////////

// Win32 can do more accurate profiling than the default
#define PROFILE_T   __int64
#define AddTime(x)  sprintf(sz + strlen(sz), "  %s:%I64dus", #x, (s_sProfile.prof##x + 5) / 10i64)


class OSD
{
    public:
        static bool Init (bool fFirstInit_=false);
        static void Exit (bool fReInit_=false);

        static PROFILE_T GetProfileTime ();
        static DWORD GetTime ();
        static const char* GetFilePath (const char* pcszFile_="");
        static const char* GetFloppyDevice (int nDrive_);
        static bool CheckPathAccess (const char* pcszPath_);
        static bool IsHidden (const char* pcszFile_);

        static void DebugTrace (const char* pcsz_);
        static int FrameSync (bool fWait_=true);

        static int s_nTicks;
};

#endif
