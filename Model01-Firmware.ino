// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#define DEBUG_SERIAL false

#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-Numlock.h"
#include "Kaleidoscope.h"

#include "LED-Off.h"
#include "Kaleidoscope-LEDEffect-SolidColor.h"
#include "Kaleidoscope-LEDEffect-Breathe.h"
#include "Kaleidoscope-LEDEffect-Chase.h"
#include "Kaleidoscope-LEDEffect-Rainbow.h"
#include "Kaleidoscope-Model01-TestMode.h"


#define MACRO_ANY 2
#define Key_Any M(MACRO_ANY)
#define NUMPAD_KEYMAP 2

#define COLEMAK KEYMAP ( \
	___,          Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDEffectNext, 	___,       Key_6, Key_7, Key_8,     Key_9,      Key_0, 	       Key_ToggleNumlock, \
	Key_Backtick, Key_Q, Key_W, Key_F, Key_P, Key_G, Key_Tab, 		Key_Enter, Key_J, Key_L, Key_U,     Key_Y,      Key_Semicolon, Key_Equals, \
	Key_PageUp,   Key_A, Key_R, Key_S, Key_T, Key_D,                     		   Key_H, Key_N, Key_E,     Key_I,      Key_O,         Key_Quote, \
	Key_PageDn,   Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Esc, 		___,       Key_K, Key_M, Key_Comma, Key_Period, Key_Slash,     Key_Minus,\
	                    Key_LCtrl, Key_Backspace, Key_LGUI, Key_LShift,	Key_RShift, Key_RAlt, Key_Space, Key_RCtrl,\
			                             Key_Keymap1_Momentary, 	Key_Keymap1_Momentary,\
)

#define DVORAK KEYMAP ( \
	___, 	      Key_1, 	     Key_2,     Key_3, 	    Key_4, Key_5, Key_LEDEffectNext, 	___,       Key_6, Key_7, Key_8, Key_9, Key_0, Key_ToggleNumlock, \
	Key_Backtick, Key_Quote,     Key_Comma, Key_Period, Key_P, Key_Y, Key_Tab, 		Key_Enter, Key_F, Key_G, Key_C, Key_R, Key_L, Key_Slash, \
	Key_PageUp,   Key_A, 	     Key_O,     Key_E, 	    Key_U, Key_I, 				   Key_D, Key_H, Key_T, Key_N, Key_S, Key_Minus, \
	Key_PageDn,   Key_Semicolon, Key_Q,     Key_J, 	    Key_K, Key_X, Key_Esc, 		___, 	   Key_B, Key_M, Key_W, Key_V, Key_Z, Key_Equals, \
				   Key_LCtrl, Key_Backspace, Key_LGUI, Key_LShift,		Key_RShift, Key_RAlt, Key_Space, Key_RCtrl, \
					      		  Key_KeymapNext_Momentary, 		Key_KeymapNext_Momentary \
)

#define GENERIC_FN2  KEYMAP_STACKED ( \
 	___,      Key_F1,       Key_F2,      Key_F3,     Key_F4,          Key_F5,          XXX,  	  \
	Key_Tab,  ___, 		Key_mouseUp, ___,        Key_mouseBtnL, Key_mouseWarpEnd, Key_mouseWarpNE, 	 \
	Key_Home, Key_mouseL,   Key_mouseDn, Key_mouseR, Key_mouseBtnM, Key_mouseWarpNW, \
	Key_End,  ___,         	___,         ___,     	 Key_mouseBtnR, Key_mouseWarpSW, Key_mouseWarpSE,    \
							Key_LCtrl, Key_Delete, Key_LGUI, Key_LShift,		\
					      				      ___,\
\
	Key_prevTrack,        Key_F6,         Key_F7,            Key_F8, 		  Key_F9,	      Key_F10, 		  Key_F11,\
	Key_playPause,	      ___,  	      Key_LCurlyBracket, Key_RCurlyBracket, Key_LSquareBracket, Key_RSquareBracket,	Key_F12,\
		    	      Key_LArrow,     Key_DnArrow,       Key_UpArrow, 	  Key_RArrow, 	     ___,           ___,\
	Key_nextTrack,        Key_volumeMute, Key_volumeDown,    Key_volumeUp,        ___,    Key_Backslash,      Key_Pipe,\
	Key_RShift, Key_RAlt, Key_Enter, Key_RCtrl,\
	___\
)



#define MALTRON KEYMAP ( \
 	___, 	      Key_1, 	 Key_2,      Key_3, Key_4, Key_5,     Key_LEDEffectNext,	___,       Key_6,         Key_7, Key_8, Key_9,     Key_0, Key_ToggleNumlock, \
	Key_Backtick, Key_Q, 	 Key_P,      Key_Y, Key_C, Key_B,     Key_Tab, 			Key_Enter, Key_V, 	  Key_M, Key_U, Key_Z,     Key_L, Key_Equals, \
	Key_PageUp,   Key_A, 	 Key_N,      Key_I, Key_S, Key_F, 				           Key_D, 	  Key_T, Key_H, Key_O,     Key_R, Key_Quote, \
	Key_PageDn,   Key_Comma, Key_Period, Key_J, Key_G, Key_Slash, Key_Esc, 			___, 	   Key_Semicolon, Key_W, Key_K, Key_Minus, Key_X, Key_LSquareBracket, \
			Key_E, Key_Backspace, Key_LGUI, Key_LShift,		Key_RShift, Key_RAlt, Key_Space, Key_RCtrl, \
					      Key_KeymapNext_Momentary, 	Key_KeymapNext_Momentary \
)

#define NUMPAD KEYMAP  (\
 	___, ___, ___, ___, ___, ___, ___,  		        ___, ___, Key_Keypad7, Key_Keypad8,   Key_Keypad9,        Key_KeypadMinus, ___, \
	___, ___, ___, ___, ___, ___, ___,   		        ___, ___, Key_Keypad4, Key_Keypad5,   Key_Keypad6,        Key_KeypadPlus,  ___, \
	___, ___, ___, ___, ___, ___,                 	             ___, Key_Keypad1, Key_Keypad2,   Key_Keypad3,        Key_Equals,      Key_Quote, \
	___, ___, ___, ___, ___, ___, ___,                      ___, ___, Key_Keypad0, Key_KeypadDot, Key_KeypadMultiply, Key_KeypadSlash, Key_Enter, \
		       ___, ___, ___, ___,			___, ___, ___, ___, \
			         Key_Keymap1_Momentary, 	Key_Keymap1_Momentary \
)

#define QWERTY KEYMAP ( \
	___, 	      Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDEffectNext, 	Key_Any,   Key_6, Key_7, Key_8,     Key_9,      Key_0,         Key_ToggleNumlock, \
	Key_Backtick, Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab, 	  	Key_Enter, Key_Y, Key_U, Key_I,     Key_O,      Key_P,         Key_Equals, \
	Key_PageUp,   Key_A, Key_S, Key_D, Key_F, Key_G,  		     		   Key_H, Key_J, Key_K,     Key_L, 	Key_Semicolon, Key_Quote, \
	Key_PageDn,   Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Esc, 		Key_RAlt,  Key_N, Key_M, Key_Comma, Key_Period, Key_Slash,     Key_Minus, \
			Key_LCtrl, Key_Backspace, Key_LGUI, Key_LShift,		Key_RShift, Key_LAlt, Key_Space, Key_RCtrl, \
					      Key_KeymapNext_Momentary, 	Key_KeymapNext_Momentary \
)

#define WORKMAN KEYMAP  ( \
	___,          Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDEffectNext,	___,	    Key_6, Key_7, Key_8, Key_9, Key_0, Key_ToggleNumlock, \
	Key_Backtick, Key_Q, Key_D, Key_R, Key_W, Key_B, Key_Tab, 		Key_Enter,  Key_J, Key_F, Key_U, Key_P, Key_Semicolon, Key_Equals, \
	Key_PageUp,   Key_A, Key_S, Key_H, Key_T, Key_G,  		  		    Key_Y, Key_N, Key_E, Key_O, Key_I, Key_Quote, \
	Key_PageDn,   Key_Z, Key_X, Key_M, Key_C, Key_V, Key_Esc, 		___, 	    Key_K, Key_L, Key_Comma, Key_Period, Key_Slash, Key_Minus, \
			Key_LCtrl, Key_Backspace, Key_LGUI, Key_LShift,		Key_RShift, Key_RAlt, Key_Space, Key_RCtrl, \
					      Key_KeymapNext_Momentary, 	Key_KeymapNext_Momentary \
)

const Key keymaps[][ROWS][COLS] PROGMEM = { 
	QWERTY, 
	GENERIC_FN2,
	NUMPAD


 };

static LEDSolidColor solidRed (60, 0, 0);
static LEDSolidColor solidOrange (60, 20, 0);
static LEDSolidColor solidYellow (40, 35, 0);
static LEDSolidColor solidGreen (0, 100, 0);
static LEDSolidColor solidBlue (0, 15, 100);
static LEDSolidColor solidIndigo (0, 0, 100);
static LEDSolidColor solidViolet (70, 0, 60);

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
    if (macroIndex == TOGGLENUMLOCK && key_toggled_on(keyState)) {
        return NumLock.toggle (Macros.row, Macros.col, NUMPAD_KEYMAP);
    } else if (macroIndex == 1 && key_toggled_on(keyState)) {
        Serial.print("Keyboard.IO keyboard driver v0.00");
        return MACRO(I(25),
                     D(LShift), T(M), U(LShift), T(O), T(D), T(E), T(L),
                     T(Space),
                     W(100),
                     T(0), T(1),
                     END);
    } else if (macroIndex == MACRO_ANY && key_toggled_on(keyState)) {
	Keyboard.press(Key_A.keyCode + (uint8_t)(millis() % 36) );
	Keyboard.sendReport();
    }
    return MACRO_NONE;
}

void setup() {
    Kaleidoscope.setup(KEYMAP_SIZE);

    Kaleidoscope.use(&TestMode,
                     &LEDControl, &LEDOff,
                     &solidRed, &solidOrange, &solidYellow, &solidGreen, &solidBlue, &solidIndigo, &solidViolet,
                     &LEDBreatheEffect, &LEDRainbowEffect, &LEDChaseEffect, &NumLock,

                     &Macros,
                     &MouseKeys,
                     NULL);

    LEDOff.activate();
}


void loop() {
    Kaleidoscope.loop();
}
