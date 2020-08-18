/* -*- mode: c++ -*-
 * ErgoDox -- A very basic Kaleidoscope example for the ErgoDox
 * Copyright (C) 2018  Keyboard.io, Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include "Kaleidoscope.h"

#include <Kaleidoscope-OneShot.h>
#include <Kaleidoscope-Escape-OneShot.h>
#include <Kaleidoscope-Qukeys.h>


enum { PRIMARY, FUNCTION }; // layers

#define Key_AT    LSHIFT(Key_2)
#define Key_STAR  LSHIFT(Key_8)
#define Key_DOLLR LSHIFT(Key_4)
#define Key_CARET LSHIFT(Key_6)
#define Key_PRCNT LSHIFT(Key_5)
#define Key_EXCLM LSHIFT(Key_1)
#define Key_HASH  LSHIFT(Key_3)
#define Key_AND   LSHIFT(Key_7)
#define Key_LP   LSHIFT(Key_9)
#define Key_RP   LSHIFT(Key_0)
#define Key_LCB   LSHIFT(Key_LeftBracket)
#define Key_RCB   LSHIFT(Key_RightBracket)
#define Key_UNDSCR   LSHIFT(Key_Minus)


/* *INDENT-OFF* */
KEYMAPS(
  [PRIMARY] = KEYMAP_STACKED
  (
      // left hand
      Key_Equals,             Key_1,         Key_2,     Key_3,         Key_4,   Key_5,   LCTRL(Key_Spacebar),
      Key_Delete,             Key_Q,         Key_W,     Key_F,         Key_P,   Key_G,   Key_Tab,
      MT(LeftGui, Esc),       Key_A,         Key_R,     Key_S,         Key_T,   Key_D,
      Key_LeftShift,          Key_Z,         Key_X,     Key_C,         Key_V,   Key_B,   MT(LCtrl, Esc),
      Key_Backtick,           Key_Quote,     Key_NoKey, Key_LeftArrow, Key_RightArrow,

      Key_NoKey, Key_LeftGui,
      Key_Home,
      LT(FUNCTION, Enter), Key_Backspace, Key_End,

      // right hand
      LCTRL(Key_Spacebar),   Key_6,         Key_7,  Key_8,     Key_9,      Key_0,         Key_Minus,
      Key_Enter,             Key_J,         Key_L,  Key_U,     Key_Y,      Key_Semicolon, Key_Backslash,
                             Key_H,         Key_N,  Key_E,     Key_I,      Key_O,         MT(LeftGui, Quote),
      Key_RightControl,      Key_K,         Key_M,  Key_Comma, Key_Period, Key_Slash,     Key_RightShift,
      Key_UpArrow,           Key_DownArrow, XXX,    XXX,          Key_NoKey,

      Key_LeftAlt,  Key_Esc,
      Key_PageUp,
      Key_PageDown, Key_Tab, LT(FUNCTION, Space)
  ),
  [FUNCTION] = KEYMAP_STACKED
  (
      // left hand
      ___,      ___,         ___,     ___,         ___,   ___,   ___,
      ___,      Key_EXCLM, Key_AT, Key_LCB,     Key_RCB,  Key_Pipe,   ___,
      ___,      Key_HASH, Key_DOLLR, Key_LP, Key_RP, Key_Backslash,   
      ___,      Key_PRCNT,  Key_CARET,  Key_LeftBracket,        Key_RightBracket, Key_UNDSCR,   ___,
      ___,      ___,     ___, ___, ___,

      ___, ___,
      ___,
      ___, ___, ___,

      // right hand
      ___,   ___,         ___,  ___,     ___,      ___,         ___,
      ___,   ___,         ___,  ___,     ___,      ___,         ___,
             Key_LeftArrow,          Key_DownArrow,            Key_UpArrow,              Key_RightArrow,     ___, ___,
      ___,   ___,         ___,  ___,     ___,       ___,        ___,
      ___,   ___,         ___,   ___,          ___,

      ___,  ___,
      ___,
      ___, ___, ___
  ),
)
/* *INDENT-ON* */

KALEIDOSCOPE_INIT_PLUGINS(
	OneShot,
        EscapeOneShot, 
	Qukeys
);

void setup() {
  Kaleidoscope.setup();
}

void loop() {
  Kaleidoscope.loop();
}
