// -*- mode: c++ -*-

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif


#define KALEIDOSCOPE_HOSTOS_GUESSER 1


#include "Kaleidoscope.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-LEDControl.h"
#include "LED-Off.h"
#include "Kaleidoscope-LEDEffect-BootGreeting.h"
#include "Kaleidoscope-LEDEffect-SolidColor.h"
#include "Kaleidoscope-LEDEffect-Breathe.h"
#include "Kaleidoscope-LEDEffect-Chase.h"
#include "Kaleidoscope-LEDEffect-Rainbow.h"
#include "Kaleidoscope-LED-Stalker.h"
#include "Kaleidoscope-LED-AlphaSquare.h"
#include "Kaleidoscope-Model01-TestMode.h"
#include "Kaleidoscope-HostPowerManagement.h"
#include <Kaleidoscope-HostOS.h>
#include <Kaleidoscope/HostOS-select.h>
#include <Kaleidoscope-Unicode.h>
#include <Kaleidoscope-LEDEffect-DigitalRain.h>
#include <Kaleidoscope-OneShot.h>


enum { MACRO_VERSION_INFO,
       MACRO_ANY,
       MACRO_UNICODE_CRAZY, // 🤪 (0x1F92A)
       MACRO_UNICODE_EYES, // 😳 (0x1F633)
       MACRO_UNICODE_FLOWER, // 🌻 (0x1F33B)
       MACRO_UNICODE_GRIMACE, // 😬 (0x1F62C)
       MACRO_UNICODE_KISS, // 😘 (0x1F618)
       MACRO_UNICODE_LOL, // 😂 (0x1F602)
       MACRO_UNICODE_PEACH, // 🍑 (0x1F351)
       MACRO_UNICODE_SMILE, // 😊 (0x1F60A)
       MACRO_UNICODE_THUMB, // 👍 (0x1F44D)
       MACRO_UNICODE_UNICORN, // 🦄 (0x1F984)
       MACRO_UNICODE_WAVING, // 👋 (0x1F44B)
       MACRO_LED_NEXT_PREV,
       MACRO_LED_TOGGLE_ON_OFF,
       MACRO_UMLAUT_A,
       MACRO_UMLAUT_O,
       MACRO_UMLAUT_U,
       MACRO_SZ,
     };


enum { QWERTY,
       FUNCTION_LEFT,
       FUNCTION_RIGHT,
       MACROS,
     };


/**
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keyboard.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_consumerctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_sysctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keymaps.h
  */

// *INDENT-OFF*

KEYMAPS(

  [QWERTY] = KEYMAP_STACKED
  (___,          Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDEffectNext,
   Key_Backtick, Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
   Key_PageUp,   Key_A, Key_S, Key_D, Key_F, Key_G,
   Key_PageDown, Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,
   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
   ShiftToLayer(FUNCTION_LEFT),

   M(MACRO_ANY),         Key_6, Key_7, Key_8,     Key_9,         Key_0,         M(MACRO_SZ),
   Key_Enter,            Key_Y, Key_U, Key_I,     Key_O,         Key_P,         Key_Equals,
                         Key_H, Key_J, Key_K,     Key_L,         Key_Semicolon, Key_Quote,
   OSL(MACROS), Key_N, Key_M, Key_Comma, Key_Period,    Key_Slash,     Key_Minus,
   Key_RightShift, Key_LeftAlt, Key_Spacebar, Key_RightControl,
   ShiftToLayer(FUNCTION_RIGHT)),


  [FUNCTION_LEFT] =  KEYMAP_STACKED
  (___,      Key_F1,           Key_F2,      Key_F3,     Key_F4,        Key_F5,           M(MACRO_LED_TOGGLE_ON_OFF),
   Key_Tab,  ___,              Key_mouseUp, ___,        Key_mouseBtnR, Key_mouseWarpEnd, Key_mouseWarpNE,
   Key_Home, Key_mouseL,       Key_mouseDn, Key_mouseR, Key_mouseBtnL, Key_mouseWarpNW,
   Key_End,  Key_PrintScreen,  Key_Insert,  ___,        Key_mouseBtnM, Key_mouseWarpSW,  Key_mouseWarpSE,
   ___, Key_Delete, ___, ___,
   ___,

   Consumer_ScanPreviousTrack, Key_F6,                 Key_F7,                   Key_F8,                   Key_F9,          Key_F10,           Key_F11,
   Consumer_PlaySlashPause,    Consumer_ScanNextTrack, Key_LeftCurlyBracket,     Key_RightCurlyBracket,    Key_LeftBracket, Key_RightBracket,  M(MACRO_UMLAUT_U),
                               Key_LeftArrow,          Key_DownArrow,            Key_UpArrow,              Key_RightArrow,  M(MACRO_UMLAUT_O), M(MACRO_UMLAUT_A),
   Key_PcApplication,          Consumer_Mute,          Consumer_VolumeDecrement, Consumer_VolumeIncrement, ___,             Key_Backslash,     Key_Pipe,
   ___, ___, Key_Enter, ___,
   ___),


  [FUNCTION_RIGHT] =  KEYMAP_STACKED
  (___,      Key_F1,           Key_F2,      Key_F3,     Key_F4,        Key_F5,           M(MACRO_LED_NEXT_PREV),
   Key_Tab,  ___,              Key_mouseUp, ___,        Key_mouseBtnR, Key_mouseWarpEnd, Key_mouseWarpNE,
   Key_Home, Key_mouseL,       Key_mouseDn, Key_mouseR, Key_mouseBtnL, Key_mouseWarpNW,
   Key_End,  Key_PrintScreen,  Key_Insert,  ___,        Key_mouseBtnM, Key_mouseWarpSW,  Key_mouseWarpSE,
   ___, Key_Delete, ___, ___,
   ___,

   Consumer_ScanPreviousTrack, Key_F6,                 Key_F7,                   Key_F8,                   Key_F9,          Key_F10,          Key_F11,
   Consumer_PlaySlashPause,    Consumer_ScanNextTrack, Key_LeftCurlyBracket,     Key_RightCurlyBracket,    Key_LeftBracket, Key_RightBracket, Key_F12,
                               Key_LeftArrow,          Key_DownArrow,            Key_UpArrow,              Key_RightArrow,  ___,              ___,
   Key_PcApplication,          Consumer_Mute,          Consumer_VolumeDecrement, Consumer_VolumeIncrement, ___,             Key_Backslash,    Key_Pipe,
   ___, ___, Key_Enter, ___,
   ___), 


  [MACROS] =  KEYMAP_STACKED
  (___, ___, ___,                     ___,                    ___,                     ___,                      ___,
   ___, ___, M(MACRO_UNICODE_WAVING), M(MACRO_UNICODE_EYES),  ___,                     M(MACRO_UNICODE_THUMB),   ___,
   ___, ___, M(MACRO_UNICODE_SMILE),  ___,                    M(MACRO_UNICODE_FLOWER), M(MACRO_UNICODE_GRIMACE),
   ___, ___, ___,                     M(MACRO_UNICODE_CRAZY), ___,                     ___,                      ___,
   ___, ___, ___, ___,
   ___,

   ___, ___, ___,                      ___,                   ___,                  ___,                    ___,
   ___, ___, M(MACRO_UNICODE_UNICORN), ___,                   ___,                  M(MACRO_UNICODE_PEACH), ___,
        ___, ___,                      M(MACRO_UNICODE_KISS), M(MACRO_UNICODE_LOL), ___,                    ___,
   ___, ___, ___,                      ___,                   ___,                  ___,                    ___,
   ___, ___, ___, ___,
   ___)

	) // KEYMAPS(

// *INDENT-ON*


static void versionInfoMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope "));
    Macros.type(PSTR(BUILD_INFORMATION));
  }
}


static void anyKeyMacro(uint8_t keyState) {
  static Key lastKey;
  if (keyToggledOn(keyState))
    lastKey.keyCode = Key_A.keyCode + (uint8_t)(millis() % 36);

  if (keyIsPressed(keyState))
    kaleidoscope::hid::pressKey(lastKey);
}


static void unicode(uint32_t character, uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Unicode.type(character);
  }
}


static void umlaut(Key key, uint8_t keyState) {
  if (!keyToggledOn(keyState)) {
    return;
  }

  tap(Key_RightAlt); // why?

  bool left_shift_active = kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift);
  if (left_shift_active) {
    release(Key_LeftShift);
  }

  bool right_shift_active = kaleidoscope::hid::wasModifierKeyActive(Key_RightShift);
  if (right_shift_active) {
    release(Key_RightShift);
  }

  press(Key_RightAlt);
  tap(Key_U);
  release(Key_RightAlt);

  if (left_shift_active) {
    press(Key_LeftShift);
  }
  if (right_shift_active) {
    press(Key_RightShift);
  }

  tap(key);
}

static void press(Key key) {
  kaleidoscope::hid::pressKey(key);
  kaleidoscope::hid::sendKeyboardReport();
}

static void release(Key key) {
  kaleidoscope::hid::releaseKey(key);
  kaleidoscope::hid::sendKeyboardReport();
}

static void tap(Key key) {
  press(key);
  release(key);
}


static int lastLedModeIndex = -1;

static void toggleLedsOnOff(uint8_t key_state) {
  if (keyToggledOn(key_state)) {
    if (LEDControl.get_mode() != &LEDOff) {
      lastLedModeIndex = LEDControl.get_mode_index();
      LEDOff.activate();
    } else if (lastLedModeIndex >= 0) {
      LEDControl.set_mode(lastLedModeIndex);
    } else {
      nextPrevLedMode(key_state);
    }
  }
}

static void nextPrevLedMode(uint8_t key_state) {
  if (keyToggledOn(key_state)) {
    if (shiftKeyActive()) {
      prevLedModeSkippingOff();
    } else {
      nextLedModeSkippingOff();
    }
    lastLedModeIndex = LEDControl.get_mode_index();
  }
}

static void nextLedModeSkippingOff() {
  do {
    LEDControl.next_mode();
  } while (LEDControl.get_mode() == &LEDOff);
}

static void prevLedModeSkippingOff() {
  do {
    LEDControl.prev_mode();
  } while (LEDControl.get_mode() == &LEDOff);
}

static bool shiftKeyActive(void) {
  return kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift) ||
         kaleidoscope::hid::wasModifierKeyActive(Key_RightShift);
}


const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {

  case MACRO_VERSION_INFO:
    versionInfoMacro(keyState);
    break;

  case MACRO_ANY:
    anyKeyMacro(keyState);
    break;

  case MACRO_UNICODE_CRAZY:
    unicode(0x1F92A, keyState);
    break;

  case MACRO_UNICODE_EYES:
    unicode(0x1F633, keyState);
    break;

  case MACRO_UNICODE_GRIMACE:
    unicode(0x1F62C, keyState);
    break;

  case MACRO_UNICODE_KISS:
    unicode(0x1F618, keyState);
    break;

  case MACRO_UNICODE_LOL:
    unicode(0x1F602, keyState);
    break;

  case MACRO_UNICODE_PEACH:
    unicode(0x1F351, keyState);
    break;

  case MACRO_UNICODE_SMILE:
    unicode(0x1F60A, keyState);
    break;

  case MACRO_UNICODE_FLOWER:
    unicode(0x1F33B, keyState);
    break;

  case MACRO_UNICODE_THUMB:
    unicode(0x1F44D, keyState);
    break;

  case MACRO_UNICODE_UNICORN:
    unicode(0x1F984, keyState);
    break;

  case MACRO_UNICODE_WAVING:
    unicode(0x1F44B, keyState);
    break;

  case MACRO_LED_TOGGLE_ON_OFF:
    toggleLedsOnOff(keyState);
    break;

  case MACRO_LED_NEXT_PREV:
    nextPrevLedMode(keyState);
    break;

  case MACRO_UMLAUT_A:
    umlaut(Key_A, keyState);
    break;

  case MACRO_UMLAUT_O:
    umlaut(Key_O, keyState);
    break;

  case MACRO_UMLAUT_U:
    umlaut(Key_U, keyState);
    break;

  case MACRO_SZ:
    return MACRODOWN(D(RightAlt), T(S), U(RightAlt));
  }
  return MACRO_NONE;
}


static kaleidoscope::LEDSolidColor solidRed(160, 0, 0);
static kaleidoscope::LEDSolidColor solidOrange(140, 70, 0);
static kaleidoscope::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::LEDSolidColor solidGreen(0, 160, 0);
static kaleidoscope::LEDSolidColor solidBlue(0, 70, 130);
static kaleidoscope::LEDSolidColor solidIndigo(0, 0, 170);
static kaleidoscope::LEDSolidColor solidViolet(130, 0, 120);


void toggleLedsOnSuspendResume(kaleidoscope::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::HostPowerManagement::Suspend:
    LEDControl.paused = true;
    LEDControl.set_all_leds_to({0, 0, 0});
    LEDControl.syncLeds();
    break;
  case kaleidoscope::HostPowerManagement::Resume:
    LEDControl.paused = false;
    LEDControl.refreshAll();
    break;
  case kaleidoscope::HostPowerManagement::Sleep:
    break;
  }
}


void hostPowerManagementEventHandler(kaleidoscope::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}


void setup() {
  Kaleidoscope.setup();

  Kaleidoscope.use(
    &BootGreetingEffect,
    &TestMode,
    &LEDControl,

    &LEDOff,
    &LEDRainbowEffect,
    &LEDRainbowWaveEffect,
    &LEDChaseEffect,
    &solidRed, &solidOrange, &solidYellow, &solidGreen, &solidBlue, &solidIndigo, &solidViolet,
    &LEDBreatheEffect,
    &AlphaSquareEffect,
    &StalkerEffect,
    &LEDDigitalRainEffect,

    &Macros,
    &Unicode,
    &OneShot,
    &MouseKeys,
    &HostPowerManagement
  );

  AlphaSquare.color = CRGB(255, 0, 0);

  LEDRainbowEffect.brightness(150); // 0-255
  LEDRainbowWaveEffect.brightness(150); // 0-255

  StalkerEffect.variant = STALKER(BlazingTrail);

  HostPowerManagement.enableWakeup();

  LEDOff.activate();
}


void loop() {
  Kaleidoscope.loop();
}
