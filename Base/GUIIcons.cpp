// Part of SimCoupe - A SAM Coup� emulator
//
// GUIIcons.cpp: Handy icons for the GUI
//
//  Copyright (c) 1999-2001  Simon Owen
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

//  Notes:
//      Icons are 32x32 in size, and each have a private palette taken
//      from the GUI palette.  A zero in the palette is taken to be
//      a transparent pixel.  The image data is simply an index into
//      the icons logical palette.

#include "SimCoupe.h"

#include "GUI.h"
#include "GUIIcons.h"


const GUI_ICON sMouseCursor =
{
    { 0, BLACK, WHITE },

    {
        { 2,2 },
        { 2,1,2 },
        { 2,1,1,2 },
        { 2,1,1,1,2 },
        { 2,1,1,1,1,2 },
        { 2,1,1,1,1,1,2 },
        { 2,1,1,1,1,1,1,2 },
        { 2,1,1,1,1,1,1,1,2 },
        { 2,1,1,1,1,1,1,1,1,2 },
        { 2,1,1,1,1,1,2,2,2,2,2 },
        { 2,1,1,2,1,1,2 },
        { 2,1,2,0,2,1,1,2 },
        { 2,2,0,0,2,1,1,2 },
        { 2,0,0,0,0,2,1,1,2 },
        { 0,0,0,0,0,2,1,1,2 },
        { 0,0,0,0,0,0,2,2 }
    }
};

const GUI_ICON sSamIcon = 
{
    { 0, BLACK, GREY_5, GREY_7 },

    {
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,2,1,1,1 },
        { 0,0,0,0,0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,1,1 },
        { 0,0,0,0,0,0,0,0,0,1,2,2,3,3,2,2,2,2,2,2,2,1 },
        { 0,0,0,0,0,0,0,0,1,2,2,3,2,2,2,2,2,2,2,2,2,2,1 },
        { 0,0,0,0,0,0,0,1,2,2,3,2,2,2,2,2,2,2,2,2,2,2,2,1 },
        { 0,0,0,0,0,0,0,1,2,3,2,2,2,2,2,2,2,2,2,2,2,2,2,1 },
        { 0,0,0,0,0,0,1,2,2,3,2,2,2,1,2,2,2,1,2,2,2,2,2,2,1 },
        { 0,0,0,0,0,0,1,2,2,2,2,2,2,1,2,2,2,1,2,2,2,2,2,2,1 },
        { 0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1 },
        { 0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1 },
        { 0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
        { 0,0,0,0,1,0,0,0,0,0,0,1,1,2,2,2,2,2,1,1,0,0,0,0,0,0,1 },
        { 0,0,0,1,2,1,0,0,0,1,1,2,2,2,2,2,2,2,2,2,1,1,0,0,0,1,2,1 },
        { 0,0,1,2,2,1,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,1,2,2,1 },
        { 0,1,2,3,2,2,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,2,3,2,2,1 },
        { 0,1,2,2,2,2,2,2,2,2,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1 },
        { 0,0,1,1,1,1,2,2,2,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1 },
        { 0,0,0,0,0,0,1,2,2,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1 },
        { 0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1 },
        { 0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1 },
        { 0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1 },
        { 0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
        { 0,0,0,0,0,0,0,0,1,1,2,2,1,1,0,0,0,1,1,2,2,1,1 },
        { 0,0,0,0,0,0,0,1,2,2,2,2,2,2,1,0,1,2,2,2,2,2,2,1 },
        { 0,0,0,0,0,0,0,1,2,3,2,2,2,2,1,0,1,2,3,2,2,2,2,1 },
        { 0,0,0,0,0,0,0,1,2,3,2,2,2,2,1,0,1,2,3,2,2,2,2,1 },
        { 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1 }
    }
};

const GUI_ICON sSoundIcon =
{
    { 0, BLACK, GREY_5, GREY_6, WHITE, YELLOW_4, YELLOW_6 },

    {
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,1,1,0,0,0,0,0,0,0,0,0,0,2 }, 
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,5,3,1,3,2,0,0,0,0,0,0,0,2,2 }, 
        { 0,0,0,0,0,0,0,0,0,0,0,0,5,3,1,3,4,3,2,0,0,0,0,2,2 }, 
        { 0,0,0,0,0,0,0,0,0,0,0,5,3,3,1,4,4,4,2,0,0,2,2 }, 
        { 0,0,0,0,0,0,0,0,0,0,5,3,6,2,2,4,4,4,4,2 }, 
        { 0,0,0,0,0,0,0,0,0,5,3,6,4,1,3,4,4,4,4,2 }, 
        { 0,0,0,0,0,0,0,0,5,3,6,4,3,1,3,4,4,4,4,2,0,0,0,0,0,0,0,0,0,0,2 }, 
        { 0,0,0,0,0,0,0,5,3,6,4,6,3,1,3,4,4,4,4,2,0,0,0,0,0,0,0,2,2,2 }, 
        { 0,0,0,0,0,0,5,3,6,4,6,4,1,2,3,4,4,4,4,4,2,0,0,0,2,2,2 }, 
        { 0,0,5,5,5,5,6,6,4,6,4,4,1,2,3,4,4,4,4,4,2,0,0,2 }, 
        { 0,5,3,3,3,5,6,4,4,4,4,4,1,2,3,4,4,4,4,4,2 }, 
        { 5,4,4,6,5,4,4,4,4,4,4,4,1,1,2,2,4,4,4,4,2 }, 
        { 5,4,4,4,5,4,4,4,4,4,4,4,1,2,4,2,1,4,4,4,2 }, 
        { 5,4,4,6,5,6,4,6,4,6,4,6,1,2,4,2,1,4,4,4,2 }, 
        { 5,4,6,4,5,4,6,4,6,4,6,4,1,2,3,2,1,4,4,4,2,0,0,2,2,2,2,2,2,2,2,2 }, 
        { 5,4,3,6,5,6,3,6,3,6,3,6,1,2,3,2,1,4,4,4,2 }, 
        { 5,4,6,3,5,3,6,3,6,3,6,3,1,2,2,2,1,4,4,4,2 }, 
        { 5,4,3,6,5,6,3,6,3,6,3,6,1,1,1,1,3,4,4,4,2 }, 
        { 0,5,5,5,5,5,6,3,6,3,6,3,1,2,2,2,3,4,4,4,2 }, 
        { 0,0,1,1,1,1,5,6,3,6,3,6,1,2,2,3,4,4,4,4,2,0,0,2 }, 
        { 0,0,0,0,0,0,1,5,6,3,6,3,1,2,3,4,4,4,4,4,2,0,0,0,2,2,2 }, 
        { 0,0,0,0,0,0,0,1,5,5,3,6,2,1,3,4,4,4,4,2,0,0,0,0,0,0,0,2,2,2 }, 
        { 0,0,0,0,0,0,0,0,1,5,5,5,3,1,3,4,4,4,4,2,0,0,0,0,0,0,0,0,0,0,2 }, 
        { 0,0,0,0,0,0,0,0,0,1,5,5,5,1,3,4,4,4,4,2 }, 
        { 0,0,0,0,0,0,0,0,0,0,1,5,5,2,2,4,4,4,4,2 }, 
        { 0,0,0,0,0,0,0,0,0,0,0,1,5,5,1,4,4,4,2,0,0,2,2 }, 
        { 0,0,0,0,0,0,0,0,0,0,0,0,1,5,1,3,4,3,2,0,0,0,0,2,2 }, 
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,1,5,1,3,2,0,0,0,0,0,0,0,2,2 }, 
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,2 }
    }
};

const GUI_ICON sDisplayIcon =
{
    { 0, BLACK, GREY_5, GREY_6, WHITE, BLUE_5, CYAN_5 },

    {
        { 0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
        { 0,0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,2,1 },
        { 0,0,0,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,2,2,1 },
        { 0,0,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,2,2,2,1 },
        { 0,2,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,1 },
        { 0,2,4,3,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,3,2,2,2,1 },
        { 0,2,4,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,3,2,2,2,1 },
        { 0,2,4,3,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,4,3,2,2,2,1 },
        { 0,2,4,3,1,5,5,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,4,3,2,2,2,1 },
        { 0,2,4,3,1,5,5,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,4,3,2,2,2,1 },
        { 0,2,4,3,1,5,5,6,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,4,3,2,2,2,1 },
        { 0,2,4,3,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,4,3,2,2,2,1 },
        { 0,2,4,3,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,4,3,2,2,2,1 },
        { 0,2,4,3,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,4,3,2,2,2,1 },
        { 0,2,4,3,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,4,3,2,2,2,1 },
        { 0,2,4,3,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,4,3,2,2,2,1 },
        { 0,2,4,3,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,4,3,2,2,2,1 },
        { 0,2,4,3,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,4,3,2,2,2,1 },
        { 0,2,4,3,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,4,3,2,2,2,1 },
        { 0,2,4,3,1,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1,4,3,2,2,2,1 },
        { 0,2,4,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,3,2,2,2,1 },
        { 0,2,4,3,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,2,2,2,1 },
        { 0,2,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,1 },
        { 0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1 },
        { 0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
        { 0,0,0,0,0,0,0,0,0,0,2,4,3,3,3,3,3,2,1 },
        { 0,0,0,0,0,0,0,2,2,2,2,4,3,3,3,3,3,3,2,2,2,2 },
        { 0,0,0,0,0,2,2,3,3,3,4,3,3,3,3,3,3,3,3,3,3,3,2,2,1 },
        { 0,0,0,0,2,4,4,4,4,4,2,3,3,3,3,3,3,3,3,3,3,3,3,2,2,1 },
        { 0,0,0,0,2,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,1 },
        { 0,0,0,0,0,1,1,3,4,4,4,4,4,4,4,4,4,4,3,3,2,2,1,1 },
        { 0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
    }
};

const GUI_ICON sKeyboardIcon =
{
    { 0, BLACK, GREY_5, GREY_6, WHITE, YELLOW_5 },

    {
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,5,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,5,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
        { 0,0,0,0,0,2,1,0,2,1,0,2,1,0,2,1,0,2,1,0,2,1,0,0,0,2 },
        { 0,0,0,2,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,0,1,1,1,2 },
        { 0,0,2 },
        { 0,0,2 },
        { 0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
        { 2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,2,1 },
        { 2,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1 },
        { 2,4,2,4,3,1,4,3,1,4,3,1,4,3,1,4,3,1,4,3,1,4,3,1,4,3,1,4,3,1,2,1 },
        { 2,4,2,3,3,1,3,3,1,3,3,1,3,3,1,3,3,1,3,3,1,3,3,1,3,3,1,3,3,1,2,1 },
        { 2,4,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1 },
        { 2,4,2,4,4,4,3,1,4,3,1,4,3,1,4,3,1,4,3,1,4,3,1,4,3,1,4,3,3,1,2,1 },
        { 2,4,2,3,3,3,3,1,3,3,1,3,3,1,3,3,1,3,3,1,3,3,1,3,3,1,3,3,3,1,2,1 },
        { 2,4,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1 },
        { 2,4,2,4,4,1,4,3,1,4,3,1,4,3,1,4,3,1,4,3,1,4,3,1,4,4,4,4,3,1,2,1 },
        { 2,4,2,3,3,1,3,3,1,3,3,1,3,3,1,3,3,1,3,3,1,3,3,1,3,3,3,3,3,1,2,1 },
        { 2,4,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1 },
        { 2,4,2,4,4,4,3,1,4,3,1,4,4,4,4,4,4,4,4,4,4,3,1,4,3,1,4,4,3,1,2,1 },
        { 2,4,2,3,3,3,3,1,3,3,1,3,3,3,3,3,3,3,3,3,3,3,1,3,3,1,3,3,3,1,2,1 },
        { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1 },
        { 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
    }
};

const GUI_ICON sMouseIcon =
{
    { 0, BLACK, GREY_5, GREY_6, WHITE },

    {
        { 0,0,0,2,2,2,2,2 },
        { 0,0,2,1,1,1,1,1 },
        { 0,2,1 },
        { 0,1,2 },
        { 0,1,2 },
        { 0,0,1,2,2 },
        { 0,0,0,1,1,2,2,0,0,0,2,2,2,2,2,2,2,2 },
        { 0,0,0,0,0,1,1,2,2,2,4,2,3,3,3,3,3,2,2,1 },
        { 0,0,0,0,0,0,2,2,4,4,4,4,2,2,3,3,3,3,3,2,1 },
        { 0,0,0,0,0,0,2,4,4,4,4,4,4,4,2,1,1,1,1,1,1,1 },
        { 0,0,0,0,0,2,4,4,4,4,4,4,2,2,4,4,3,3,3,3,3,2,1 },
        { 0,0,0,0,2,4,4,4,4,4,4,2,4,4,4,4,4,4,4,3,4,3,2,1 },
        { 0,0,0,2,4,4,4,4,4,4,2,4,4,4,4,4,4,4,4,4,3,4,3,2,1 },
        { 0,0,0,2,3,4,4,4,4,2,4,4,4,4,4,4,4,4,4,4,3,3,4,3,2,1 },
        { 0,0,0,2,3,3,4,4,2,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,2,1 },
        { 0,0,0,2,3,3,3,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,2,1 },
        { 0,0,0,2,4,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,3,4,3,3,3,1 },
        { 0,0,0,0,2,4,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,2,1 },
        { 0,0,0,0,0,2,4,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,3,4,3,3,3,2,1 },
        { 0,0,0,0,0,0,2,4,3,3,3,3,4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,2,1 },
        { 0,0,0,0,0,0,0,2,4,3,3,3,4,4,4,4,4,4,4,4,4,4,3,4,3,3,3,3,2,1 },
        { 0,0,0,0,0,0,0,0,2,4,3,3,3,4,4,4,4,4,4,4,4,4,4,3,3,3,3,3,2,1 },
        { 0,0,0,0,0,0,0,0,0,2,4,3,3,4,4,4,4,4,4,4,4,4,3,3,3,3,3,3,2,1 },
        { 0,0,0,0,0,0,0,0,0,2,4,3,3,4,4,4,4,4,4,4,4,3,4,3,3,3,3,3,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,2,4,3,3,4,4,4,4,4,4,4,4,3,3,3,3,3,2,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,2,4,3,3,4,4,4,4,4,4,3,3,3,3,3,3,3,2,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,2,4,3,4,4,4,4,4,3,4,3,3,3,3,3,2,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,2,4,3,4,4,4,3,4,3,3,3,3,3,2,2,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,2,4,3,3,3,3,3,3,3,3,3,2,2,2,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,2,4,3,3,3,3,3,3,2,2,2,2,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,1,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1 }
    }
};

const GUI_ICON sHardwareIcon = 
{
    { 0, BLACK, GREY_5, GREY_6, WHITE, RED_3, RED_5, GREEN_5, GREEN_7, YELLOW_5 },

    {
        { 0 },
        { 0 },
        { 0 },
        { 0 },
        { 0 },
        { 0 },
        { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1 },
        { 2,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1 },
        { 2,4,7,7,7,3,7,7,7,7,3,7,7,7,3,7,8,3,8,7,8,3,7,7,7,7,3,7,7,1 },
        { 2,4,6,7,7,3,7,7,7,7,3,7,7,7,3,7,7,3,7,7,7,3,7,7,7,7,3,7,7,1 },
        { 2,4,7,7,4,3,3,1,7,4,3,3,1,7,3,7,7,3,7,7,4,3,3,3,1,7,3,3,3,1,2,1 },
        { 2,4,7,7,3,2,2,1,7,3,2,2,1,7,3,7,7,3,7,7,3,2,2,2,1,7,3,7,7,1,4,1 },
        { 2,4,6,7,1,1,1,1,7,1,1,1,1,7,3,7,7,3,7,7,3,2,2,2,1,7,3,7,7,1,3,1 },
        { 2,4,7,7,7,7,7,7,7,7,7,7,7,7,3,3,3,3,7,7,3,2,2,2,1,7,3,3,3,1,3,1 },
        { 2,4,7,7,4,3,3,1,4,3,3,1,7,3,7,7,7,7,7,7,1,1,1,1,1,7,3,7,7,1,3,1 },
        { 2,4,6,7,3,2,2,1,7,3,2,2,1,7,3,7,7,7,7,7,7,7,7,7,7,7,3,7,7,1,3,1 },
        { 2,4,7,7,1,1,1,1,7,1,1,1,1,7,3,3,3,3,8,3,3,8,3,3,8,3,3,7,7,1,3,1 },
        { 2,4,7,7,7,7,7,7,7,7,7,7,7,7,3,7,7,7,7,7,7,7,7,7,7,7,7,7,7,1,3,1 },
        { 2,4,7,7,4,3,3,1,7,4,3,3,1,7,3,7,7,7,3,2,2,1,7,3,2,2,1,7,7,1,3,1 },
        { 2,4,7,7,3,2,2,1,7,3,2,2,1,7,3,7,7,7,1,1,1,1,7,1,1,1,1,7,7,1,1,1 },
        { 2,4,7,7,1,1,1,1,7,1,1,1,1,7,3,7,7,7,7,7,7,7,7,7,7,7,7,7,7,1 },
        { 2,4,7,7,7,7,4,7,7,7,7,4,7,7,4,7,7,7,7,5,7,7,5,7,7,5,7,7,7,1 },
        { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1 },
        { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,9,2,9,2,9,2,9,2,9,2,1,1,1,1,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,9,2,9,2,9,2,9,2,9,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,9,2,9,2,9,2,9,2,9,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1 }
    }
};

const GUI_ICON sMidiIcon = 
{
    { 0, BLACK, GREY_5, GREY_6, WHITE, BLUE_3 },

    {
        { 0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5 },
        { 0,0,0,0,0,0,0,0,0,0,5,5,5,5,5,5 },
        { 0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,5 },
        { 0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,5 },
        { 1,1,1,1,1,1,1,1,1,1,5,1,1,1,1,5,1,1 },
        { 1,4,4,4,4,5,4,4,4,4,5,4,4,4,4,5,4,1 },
        { 1,1,1,1,1,5,1,1,1,5,5,1,1,1,5,5,1,1 },
        { 1,4,4,4,4,5,4,4,5,5,5,4,4,5,5,5,4,1,0,0,0,0,5,5,5,5,5,5 },
        { 1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,5,5,5,5,5,5 },
        { 1,4,4,4,4,5,4,4,4,4,4,4,4,4,4,4,4,1,0,0,0,0,5,0,0,0,0,5 },
        { 1,1,1,1,5,5,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,5,0,0,0,0,5 },
        { 0,0,0,5,5,5,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,5,0,0,0,0,5 },
        { 0,0,0,5,5,0,0,0,0,0,0,0,1,4,4,4,4,5,4,4,4,4,5,4,4,4,4,5,4,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,5,1,1,1,5,5,1,1,1,5,5,1,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,1,4,4,4,4,5,4,4,5,5,5,4,4,5,5,5,4,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,5,1,1,1,1,1,1,1,1,1,1,1,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,1,4,4,4,4,5,4,4,4,4,4,4,4,4,4,4,4,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,5,5,1,1,1,1,1,1,1,1,1,1,1,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,5 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5 },
        { 0 },
        { 0,0,0,0,0,0,0,0,0,1,1,2,0,1,1,2,0,1,1,2,0,0,0,1,1,2,0,1,1,2 },
        { 0,0,0,0,0,0,2,2,1,1,2,2,1,1,2,2,1,1,2,2,2,2,1,1,2,2,1,1,2,2,2 },
        { 0,0,0,0,0,2,4,1,1,2,2,1,1,2,2,1,1,2,2,4,3,1,1,2,2,1,1,2,2,4,4,1 },
        { 0,0,0,0,2,4,1,1,2,2,1,1,2,2,1,1,2,2,4,3,1,1,2,2,1,1,2,2,4,4,4,1 },
        { 0,0,0,2,4,4,2,2,2,4,2,2,2,4,2,2,2,4,3,4,2,2,2,4,2,2,2,4,4,4,2,1 },
        { 0,0,2,4,4,3,4,4,4,3,4,4,4,3,4,4,4,3,4,4,4,3,4,4,4,3,4,4,4,2,2,1 },
        { 0,2,4,4,3,4,4,4,3,4,4,4,3,4,4,4,3,4,4,4,3,4,4,4,3,4,4,4,2,2,1 },
        { 1,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,2,1 },
        { 1,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,1,2,2,2,1 },
        { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
    }
};

const GUI_ICON sPortIcon = 
{
    { 0, BLACK, GREY_5, GREY_6, WHITE, YELLOW_4, YELLOW_6 },

    {
        { 0,0,0,0,0,0,0,0,0,0,0,0,3,3,5,3,3,5,3,3,5,3,3,5,3,3,5,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,3,6,5,3,6,5,3,6,5,3,6,5,3,6,5,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,2,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,1 },
        { 0,0,0,0,0,0,0,0,0,0,2,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,2,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,2,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,2,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,2,4,3,3,2,3,2,3,2,3,2,3,2,2,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,2,4,4,3,3,3,3,3,3,2,3,2,3,2,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,2,4,3,3,3,3,3,3,3,3,2,3,2,2,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,2,4,4,3,3,3,3,3,3,3,3,2,3,2,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,2,4,3,3,3,3,3,3,3,3,3,3,2,2,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,2,4,4,3,3,3,3,3,3,3,3,2,3,2,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,2,4,3,3,3,3,3,3,3,3,3,3,2,2,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,1,4,3,3,3,3,3,3,3,3,2,2,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,2,2,2,2,2,2,2,2,1,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,4,3,3,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,4,3,3,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,4,3,3,2,1 },
        { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,4,3,3,3,2,1 },
        { 0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,4,3,3,3,2,1 },
        { 0,0,0,2,4,4,4,4,4,4,4,4,4,4,4,4,3,3,3,3,2,1 },
        { 0,0,2,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,1 },
        { 0,2,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,1 },
        { 2,4,3,3,3,3,2,2,2,2,2,2,2,2,2,2,2,1,1 },
        { 2,4,3,3,3,2,1,1,1,1,1,1,1,1,1,1,1 },
        { 2,4,3,3,2,1 },
        { 2,4,3,3,2,1 },
        { 2,4,3,3,2,1 },
        { 2,4,3,3,2,1 }
    }
};


const GUI_ICON sDiskIcon = 
{
    { 0, BLACK, GREY_6, WHITE, BLUE_4 },

    {
        { 4,4,4,0,0,4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,0,4,4,0,0 },
        { 4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,2,2,2,4,4,4,4,4,0 },
        { 4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,2,2,2,4,4,4,4,4,4 },
        { 4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,2,2,2,4,4,4,4,4,4 },
        { 4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,2,2,2,4,4,4,4,4,4 },
        { 4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,2,2,2,4,4,4,4,4,4 },
        { 4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,2,2,2,4,4,4,4,4,4 },
        { 4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,2,2,2,4,4,4,4,4,4 },
        { 4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,2,2,2,4,4,4,4,4,4 },
        { 4,4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4 },
        { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
        { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
        { 4,4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4 },
        { 4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4 },
        { 4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4 },
        { 4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4 },
        { 4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4 },
        { 4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4 },
        { 4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4 },
        { 4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4 },
        { 4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4 },
        { 4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4 },
        { 4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4 },
        { 4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4 },
        { 4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4 },
        { 4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4 },
        { 4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4 },
        { 4,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4 },
        { 4,1,1,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4 },
        { 4,1,1,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4 },
        { 4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4 },
    }
};

const GUI_ICON sFolderIcon = 
{
    { 0, YELLOW_1, YELLOW_2, YELLOW_3, YELLOW_4, YELLOW_5 },

    {
        { 0,0,0,2,3,3,3,3,3,2 },
        { 0,0,3,5,5,5,5,5,5,5,3 },
        { 0,3,5,5,5,5,5,5,5,5,5,3,0,0,0,0,0,0,0,0,0,0,0,0,2,3,3,3,2,1 },
        { 2,5,5,5,5,5,5,5,5,5,5,5,3,2,0,0,0,0,0,2,3,3,3,3,4,5,5,5,5,2 },
        { 3,5,5,5,5,5,5,5,5,5,5,5,5,3,3,3,3,3,3,4,5,5,5,5,5,5,5,5,4,3,3 },
        { 3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4,3,4,5,5,5,3 },
        { 3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4,3,3,4,5,5,5,5,5,5,3 },
        { 3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4,4,3,4,4,5,5,5,5,5,5,5,5,5,5,2 },
        { 3,5,5,5,5,5,5,5,5,5,5,5,5,4,3,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1 },
        { 3,5,5,5,5,5,5,5,5,4,3,3,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
        { 3,5,5,5,5,5,4,3,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4 },
        { 3,5,5,5,5,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,3 },
        { 3,5,5,5,5,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2 },
        { 3,5,5,5,5,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1 },
        { 3,5,5,5,5,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
        { 3,5,5,5,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
        { 3,5,5,5,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4 },
        { 2,4,5,5,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,3 },
        { 1,3,5,5,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2 },
        { 0,3,5,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,1 },
        { 0,3,5,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
        { 0,3,5,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 },
        { 0,3,5,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4 },
        { 0,3,5,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,3 },
        { 0,3,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,2 },
        { 0,3,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4,3,2,1},
        { 0,3,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4,3,2,1 },
        { 0,3,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,4,3,2,1 },
        { 0,3,4,5,5,5,5,5,5,5,5,5,5,4,3,2,1 },
        { 0,3,5,5,5,5,5,5,5,4,3,2,1 },
        { 0,3,5,5,5,4,3,2,1 },
        { 0,4,3,2,1 }
    }
};
