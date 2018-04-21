// -*- mode: c++ -*-

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif


#define KALEIDOSCOPE_HOSTOS_GUESSER 1
#define KALEIDOSCOPE_INCLUDE_TEST_MODE 0


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
#if KALEIDOSCOPE_INCLUDE_TEST_MODE
#include "Kaleidoscope-Model01-TestMode.h"
#endif
#include "Kaleidoscope-HostPowerManagement.h"
#include <Kaleidoscope-HostOS.h>
#include <Kaleidoscope/HostOS-select.h>
#include <Kaleidoscope-LEDEffect-DigitalRain.h>
#include <Kaleidoscope-OneShot.h>
#include <Kaleidoscope-Emoji.h>
#include <Kaleidoscope-LangPack-German.h>
#include <Kaleidoscope-LEDToggle.h>


enum { MACRO_VERSION_INFO,
       MACRO_ANY,
     };


enum { QWERTY,
       FUNCTION_LEFT,
       FUNCTION_RIGHT,
       EMOJI,
     };


/**
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keyboard.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_consumerctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_sysctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keymaps.h
  */

// *INDENT-OFF*

#define KEYMAP_QUERTY KEYMAP_STACKED
  (___,          Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDToggle,
   Key_Backtick, Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
   Key_PageUp,   Key_A, Key_S, Key_D, Key_F, Key_G,
   Key_PageDown, Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,
   Key_LeftControl, Key_Backspace, Key_LeftGui, Key_LeftShift,
   ShiftToLayer(FUNCTION_LEFT),

   M(MACRO_ANY),         Key_6, Key_7, Key_8,     Key_9,         Key_0,         Key_Eszett,
   Key_Enter,            Key_Y, Key_U, Key_I,     Key_O,         Key_P,         Key_Equals,
                         Key_H, Key_J, Key_K,     Key_L,         Key_Semicolon, Key_Quote,
   OSL(MACROS), Key_N, Key_M, Key_Comma, Key_Period,    Key_Slash,     Key_Minus,
   Key_RightShift, Key_LeftAlt, Key_Spacebar, Key_RightControl,
   ShiftToLayer(FUNCTION_RIGHT)),


  [FUNCTION_LEFT] =  KEYMAP_STACKED
  (___,      Key_F1,           Key_F2,      Key_F3,     Key_F4,        Key_F5,           Key_LEDToggleNext,
   Key_Tab,  ___,              Key_mouseUp, ___,        Key_mouseBtnR, Key_mouseWarpEnd, Key_mouseWarpNE,
   Key_Home, Key_mouseL,       Key_mouseDn, Key_mouseR, Key_mouseBtnL, Key_mouseWarpNW,
   Key_End,  Key_PrintScreen,  Key_Insert,  ___,        Key_mouseBtnM, Key_mouseWarpSW,  Key_mouseWarpSE,
   ___, Key_Delete, ___, ___,
   ___,

   Consumer_ScanPreviousTrack, Key_F6,                 Key_F7,                   Key_F8,                   Key_F9,          Key_F10,          Key_Eszett,
   Consumer_PlaySlashPause,    Consumer_ScanNextTrack, Key_LeftCurlyBracket,     Key_RightCurlyBracket,    Key_LeftBracket, Key_RightBracket, Key_UUmlaut,
                               Key_LeftArrow,          Key_DownArrow,            Key_UpArrow,              Key_RightArrow,  Key_OUmlaut,      Key_AUmlaut,
   Key_PcApplication,          Consumer_Mute,          Consumer_VolumeDecrement, Consumer_VolumeIncrement, ___,             Key_Backslash,    Key_Pipe,
   ___, ___, Key_Enter, ___,
   ___),


  [FUNCTION_RIGHT] =  KEYMAP_STACKED
  (___,      Key_F1,           Key_F2,      Key_F3,     Key_F4,        Key_F5,           Key_LEDToggleNext,
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


  [EMOJI] =  KEYMAP_STACKED
  (Key_EmojiCricket, Key_EmojiUnicornFace,   Key_EmojiEyes,  Key_EmojiSparkles,    ___,                ___,               ___,
   ___,              Key_EmojiBalloon,       Key_EmojiWave,  Key_EmojiFlushed,     Key_EmojiRocket,    Key_EmojiMetal,    ___,
   ___,              Key_EmojiWarning,       Key_EmojiSmile, Key_EmojiThumbsdown,  Key_EmojiSunflower, Key_EmojiGrimaced,
   ___,              Key_EmojiExplodingHead, Key_EmojiPeach, Key_EmojiCrazy,       Key_EmojiVulcan,    Key_EmojiBoom,     ___,
   ___, ___, ___, ___,
   ___,

   Key_EmojiUpsideDown, ___,                  ___,               ___,                  ___,                       Key_EmojiWhiteCheckMark, Key_EmojiCrossMark,
   ___,                 Key_EmojiDisbelief,   Key_EmojiThumbsup, Key_EmojiThinking,    Key_EmojiManDancing,       Key_EmojiParty,          ___,
                        Key_EmojiMischievous, Key_EmojiJoyful,   Key_EmojiFlirty,      Key_EmojiConfident,        Key_EmojiHole,           ___,
   Key_EmojiBlush,      Key_EmojiNerd,        Key_EmojiAnnoyed,  Key_EmojiWink,        Key_EmojiHourglassFlowing, Key_EmojiConstruction,   ___,
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


const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {

  case MACRO_VERSION_INFO:
    versionInfoMacro(keyState);
    break;

  case MACRO_ANY:
    anyKeyMacro(keyState);
    break;

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


void emojiTypingWillStart() {
  selectInputSourceUnicode();
}

void emojiTypingDidFinish() {
  selectInputSourceUS();
}

void selectInputSourceUS() {
  if (HostOS.os() != kaleidoscope::hostos::OSX) {
    return;
  }
  Macros.play(MACRO(D(LeftShift), D(LeftAlt), D(LeftGui), T(U), U(LeftShift), U(LeftAlt), U(LeftGui)));
}

void selectInputSourceUnicode() {
  if (HostOS.os() != kaleidoscope::hostos::OSX) {
    return;
  }
  Macros.play(MACRO(D(LeftShift), D(LeftAlt), D(LeftGui), T(H), U(LeftShift), U(LeftAlt), U(LeftGui)));
}


void setup() {
  Kaleidoscope.setup();

  Kaleidoscope.use(
    &BootGreetingEffect,
#if KALEIDOSCOPE_INCLUDE_TEST_MODE
    &TestMode,
#endif
    &LEDControl,
    &LEDToggle,

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
    &OneShot,
    &MouseKeys,
    &HostOS,
    &HostPowerManagement,
    &German
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
