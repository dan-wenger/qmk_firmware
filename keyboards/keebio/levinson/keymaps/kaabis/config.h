/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2018 Danny Nguyen <danny@keeb.io>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

// defines what's a tap and what's a hold
#define TAPPING_TERM 170 //had this on 175 for a long time
#define TAPPING_TERM_PER_KEY // for some TVP controls

// this makes my LMOD work (accessing it from HUB):
// when I press it once it gets toggled,
// when held it's just temporary
#define TAPPING_TOGGLE 1

#define ONESHOT_TAP_TOGGLE 20

// #define USE_I2C

/* Select hand configuration */
// #define MASTER_RIGHT
// #define EE_HANDS

// For Unicode Input Support.
// UC_WINC requires the WinCompose Software to be installed
// UC_WIN for testing
#define UNICODE_SELECTED_MODES UNICODE_MODE_WINCOMPOSE

