// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif


/**
 * These #include directives pull in the Kaleidoscope firmware core,
 * as well as the Kaleidoscope plugins we use in the Model 01's firmware
 */

// The Kaleidoscope core
#include "Kaleidoscope.h"

// Support for keys that move the mouse
#include "Kaleidoscope-MouseKeys.h"

// Support for macros
#include "Kaleidoscope-Macros.h"

// Support for controlling the keyboard's LEDs
#include "Kaleidoscope-LEDControl.h"

// Support for "Numpad" mode, which is mostly just the Numpad specific LED mode
#include "Kaleidoscope-NumPad.h"

// Support for an "LED off mode"
#include "LED-Off.h"

// Support for the "Boot greeting" effect, which pulses the 'LED' button for 10s
// when the keyboard is connected to a computer (or that computer is powered on)
#include "Kaleidoscope-LEDEffect-BootGreeting.h"

// Support for LED modes that set all LEDs to a single color
#include "Kaleidoscope-LEDEffect-SolidColor.h"

// Support for an LED mode that lights up the keys as you press them
#include "Kaleidoscope-LED-Stalker.h"

// Support for Keyboardio's internal keyboard testing mode
#include "Kaleidoscope-Model01-TestMode.h"

// Support for host power management (suspend & wakeup)
#include "Kaleidoscope-HostPowerManagement.h"

// Support for magic combos (key chords that trigger an action)
#include "Kaleidoscope-MagicCombo.h"

// Support for USB quirks, like changing the key state report protocol
#include "Kaleidoscope-USB-Quirks.h"

// Support for plugins
#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-Escape-OneShot.h"
#include "Kaleidoscope-LED-ActiveModColor.h"
#include "Kaleidoscope-ShapeShifter.h"
#include "Kaleidoscope-TopsyTurvy.h"

/** This 'enum' is a list of all the macros used by the Model 01's firmware
  * The names aren't particularly important. What is important is that each
  * is unique.
  *
  * These are the names of your macros. They'll be used in two places.
  * The first is in your keymap definitions. There, you'll use the syntax
  * `M(MACRO_NAME)` to mark a specific keymap position as triggering `MACRO_NAME`
  *
  * The second usage is in the 'switch' statement in the `macroAction` function.
  * That switch statement actually runs the code associated with a macro when
  * a macro key is pressed.
  */

enum {
  MACRO_VERSION_INFO,
  MACRO_ANY,
  MACRO_HYPER,
  MACRO_MEHA,
  MACRO_MEHB,
  MACRO_MEHC,
  MACRO_MEHD,
  MACRO_CMD_CTRL,
  MACRO_FAT_ARROW
};



/** The Model 01's key layouts are defined as 'keymaps'. By default, there are three
  * keymaps: The standard QWERTY keymap, the "Function layer" keymap and the "Numpad"
  * keymap.
  *
  * Each keymap is defined as a list using the 'KEYMAP_STACKED' macro, built
  * of first the left hand's layout, followed by the right hand's layout.
  *
  * Keymaps typically consist mostly of `Key_` definitions. There are many, many keys
  * defined as part of the USB HID Keyboard specification. You can find the names
  * (if not yet the explanations) for all the standard `Key_` defintions offered by
  * Kaleidoscope in these files:
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keyboard.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_consumerctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_sysctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keymaps.h
  *
  * Additional things that should be documented here include
  *   using ___ to let keypresses fall through to the previously active layer
  *   using XXX to mark a keyswitch as 'blocked' on this layer
  *   using ShiftToLayer() and LockLayer() keys to change the active keymap.
  *   the special nature of the PROG key
  *   keeping NUM and FN consistent and accessible on all layers
  *
  *
  * The "keymaps" data structure is a list of the keymaps compiled into the firmware.
  * The order of keymaps in the list is important, as the ShiftToLayer(#) and LockLayer(#)
  * macros switch to key layers based on this list.
  *
  *

  * A key defined as 'ShiftToLayer(FUNCTION)' will switch to FUNCTION while held.
  * Similarly, a key defined as 'LockLayer(NUMPAD)' will switch to NUMPAD when tapped.
  */

/**
  * Layers are "0-indexed" -- That is the first one is layer 0. The second one is layer 1.
  * The third one is layer 2.
  * This 'enum' lets us use names like QWERTY, FUNCTION, and NUMPAD in place of
  * the numbers 0, 1 and 2.
  *
  */

enum { DVORAK, QWERTY, NUMPAD, FUNCTION }; // layers

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

KEYMAPS(

  [DVORAK] = KEYMAP_STACKED
  (
    ___,          Key_1,          Key_2,       Key_3,      Key_4, Key_5, Key_LEDEffectNext,
    Key_Backtick, Key_Quote,      Key_Comma,   Key_Period, Key_P, Key_Y, Key_LeftBracket,
    Key_Tab,      Key_A,          Key_O,       Key_E,      Key_U, Key_I,
    Key_Escape,   Key_Semicolon,  Key_Q,       Key_J,      Key_K, Key_X, Key_Backslash,
    OSM(LeftControl), OSM(LeftAlt), OSM(LeftGui), OSM(LeftShift),
    ShiftToLayer(FUNCTION),

    M(MACRO_ANY),       Key_6, Key_7, Key_8, Key_9,  Key_0, LockLayer(NUMPAD),
    Key_RightBracket,          Key_F, Key_G, Key_C, Key_R,  Key_L, Key_Slash,
                        Key_D, Key_H, Key_T, Key_N,  Key_S, Key_Equals,
    M(MACRO_FAT_ARROW), Key_B, Key_M, Key_W, Key_V,  Key_Z, Key_Minus,
    OSM(RightGui), Key_Enter, Key_Spacebar, Key_Backspace,
    ShiftToLayer(FUNCTION)
  ),

  [QWERTY] = KEYMAP_STACKED
  (
    ___,          Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDEffectNext,
    Key_Backtick, Key_Q, Key_W, Key_E, Key_R, Key_T, Key_LeftBracket,
    Key_Tab,      Key_A, Key_S, Key_D, Key_F, Key_G,
    Key_Escape,   Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Backslash,
    OSM(LeftControl), OSM(LeftAlt), OSM(LeftGui), OSM(LeftShift),
    ShiftToLayer(FUNCTION),

    M(MACRO_ANY),       Key_6, Key_7, Key_8,     Key_9,         Key_0,         LockLayer(NUMPAD),
    Key_RightBracket,   Key_Y, Key_U, Key_I,     Key_O,         Key_P,         Key_Equals,
                        Key_H, Key_J, Key_K,     Key_L,         Key_Semicolon, Key_Quote,
    M(MACRO_FAT_ARROW), Key_N, Key_M, Key_Comma, Key_Period,    Key_Slash,     Key_Minus,
    OSM(RightGui),  Key_Enter, Key_Spacebar, Key_Backspace,
    ShiftToLayer(FUNCTION)
  ),

  [NUMPAD] =  KEYMAP_STACKED
  (
    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___,
    ___,

    M(MACRO_VERSION_INFO),  ___, Key_Keypad7, Key_Keypad8,   Key_Keypad9,        Key_KeypadSubtract, ___,
    ___,                    ___, Key_Keypad4, Key_Keypad5,   Key_Keypad6,        Key_KeypadAdd,      ___,
                            ___, Key_Keypad1, Key_Keypad2,   Key_Keypad3,        Key_Equals,         ___,
    ___,                    ___, Key_Keypad0, Key_KeypadDot, Key_KeypadMultiply, Key_KeypadDivide,   Key_Enter,
    ___, ___, ___, ___,
    ___
  ),

  [FUNCTION] =  KEYMAP_STACKED
  (
    LockLayer(QWERTY), Key_F1, Key_F2,          Key_F3,           Key_F4,          Key_F5,        XXX,
    Key_Tab,           Key_mouseWarpNW, Key_mouseUp,      Key_mouseWarpNE, Key_mouseBtnR, ___, ___,
    ___,               Key_mouseL,      Key_mouseDn,      Key_mouseR,      Key_mouseBtnL, ___,
    ___,               Key_mouseWarpSW, Key_mouseWarpEnd, Key_mouseWarpSE, Key_mouseBtnM, ___, ___,
    M(MACRO_MEHA), M(MACRO_MEHB), M(MACRO_MEHC), ___,
    ___,

    ___,  Key_F6, Key_F7,                       Key_F8,        Key_F9,                  Key_F10,                Key_F11,
    ___,  ___,    Key_Home,                     Key_PageDown,  Key_PageUp,              Key_End,                Key_F12,
          ___,    Key_LeftArrow,                Key_DownArrow, Key_UpArrow,             Key_RightArrow,         Consumer_VolumeIncrement,
    ___,  ___,    Consumer_ScanPreviousTrack,   Consumer_Mute, Consumer_PlaySlashPause, Consumer_ScanNextTrack, Consumer_VolumeDecrement,
    M(MACRO_CMD_CTRL), M(MACRO_HYPER), Key_Enter, Key_Delete,
    ___
  )

) // KEYMAPS(

/* Re-enable astyle's indent enforcement */
// *INDENT-ON*

/** versionInfoMacro handles the 'firmware version info' macro
 *  When a key bound to the macro is pressed, this macro
 *  prints out the firmware build information as virtual keystrokes
 */

static void versionInfoMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope "));
    Macros.type(PSTR(BUILD_INFORMATION));
  }
}

/** anyKeyMacro is used to provide the functionality of the 'Any' key.
 *
 * When the 'any key' macro is toggled on, a random alphanumeric key is
 * selected. While the key is held, the function generates a synthetic
 * keypress event repeating that randomly selected key.
 *
 */

static void anyKeyMacro(uint8_t keyState) {
  static Key lastKey;
  if (keyToggledOn(keyState))
    lastKey.keyCode = Key_A.keyCode + (uint8_t)(millis() % 36);

  if (keyIsPressed(keyState))
    kaleidoscope::hid::pressKey(lastKey);
}

/** oneShotHyperMacro is used to provide the functionality of turning
 * on OneShot functionality for Command, Option/Alt, Shift, and Ctrl keys at the same time
*/
static void oneShotHyperMacro(uint8_t keyState) {
  /* disable OneShot sticky keys */
  if (
    keyToggledOn(keyState) &&
    OneShot.isActive() &&
    OneShot.isSticky(OSM(LeftShift)) &&
    OneShot.isSticky(OSM(LeftControl)) &&
    OneShot.isSticky(OSM(LeftAlt)) &&
    OneShot.isSticky(OSM(LeftGui))
  ) {
    OneShot.inject(OSM(LeftGui), IS_PRESSED);
    OneShot.inject(OSM(LeftGui), WAS_PRESSED);

    OneShot.inject(OSM(LeftAlt), IS_PRESSED);
    OneShot.inject(OSM(LeftAlt), WAS_PRESSED);

    OneShot.inject(OSM(LeftShift), IS_PRESSED);
    OneShot.inject(OSM(LeftShift), WAS_PRESSED);

    OneShot.inject(OSM(LeftControl), IS_PRESSED);
    OneShot.inject(OSM(LeftControl), WAS_PRESSED);

    return;
  }

  /* enable OneShot sticky keys */
  if (OneShot.isActive() && keyToggledOn(keyState)) {
    OneShot.inject(OSM(LeftGui), IS_PRESSED);
    OneShot.inject(OSM(LeftGui), WAS_PRESSED);
    OneShot.inject(OSM(LeftGui), IS_PRESSED);
    OneShot.inject(OSM(LeftGui), WAS_PRESSED);

    OneShot.inject(OSM(LeftAlt), IS_PRESSED);
    OneShot.inject(OSM(LeftAlt), WAS_PRESSED);
    OneShot.inject(OSM(LeftAlt), IS_PRESSED);
    OneShot.inject(OSM(LeftAlt), WAS_PRESSED);

    OneShot.inject(OSM(LeftShift), IS_PRESSED);
    OneShot.inject(OSM(LeftShift), WAS_PRESSED);
    OneShot.inject(OSM(LeftShift), IS_PRESSED);
    OneShot.inject(OSM(LeftShift), WAS_PRESSED);

    OneShot.inject(OSM(LeftControl), IS_PRESSED);
    OneShot.inject(OSM(LeftControl), WAS_PRESSED);
    OneShot.inject(OSM(LeftControl), IS_PRESSED);
    OneShot.inject(OSM(LeftControl), WAS_PRESSED);

    return;
  }

  /* enable OneShot keys */
  OneShot.inject(OSM(LeftGui), keyState);
  OneShot.inject(OSM(LeftAlt), keyState);
  OneShot.inject(OSM(LeftShift), keyState);
  OneShot.inject(OSM(LeftControl), keyState);
}

static void oneShotMehAMacro(uint8_t keyState) {
  /* disable OneShot sticky keys */
  if (
    keyToggledOn(keyState) &&
    OneShot.isActive() &&
    OneShot.isSticky(OSM(LeftShift)) &&
    OneShot.isSticky(OSM(LeftControl)) &&
    OneShot.isSticky(OSM(LeftAlt))
  ) {
    OneShot.inject(OSM(LeftAlt), IS_PRESSED);
    OneShot.inject(OSM(LeftAlt), WAS_PRESSED);

    OneShot.inject(OSM(LeftShift), IS_PRESSED);
    OneShot.inject(OSM(LeftShift), WAS_PRESSED);

    OneShot.inject(OSM(LeftControl), IS_PRESSED);
    OneShot.inject(OSM(LeftControl), WAS_PRESSED);

    return;
  }

  /* enable OneShot sticky keys */
  if (OneShot.isActive() && keyToggledOn(keyState)) {
    OneShot.inject(OSM(LeftAlt), IS_PRESSED);
    OneShot.inject(OSM(LeftAlt), WAS_PRESSED);
    OneShot.inject(OSM(LeftAlt), IS_PRESSED);
    OneShot.inject(OSM(LeftAlt), WAS_PRESSED);

    OneShot.inject(OSM(LeftShift), IS_PRESSED);
    OneShot.inject(OSM(LeftShift), WAS_PRESSED);
    OneShot.inject(OSM(LeftShift), IS_PRESSED);
    OneShot.inject(OSM(LeftShift), WAS_PRESSED);

    OneShot.inject(OSM(LeftControl), IS_PRESSED);
    OneShot.inject(OSM(LeftControl), WAS_PRESSED);
    OneShot.inject(OSM(LeftControl), IS_PRESSED);
    OneShot.inject(OSM(LeftControl), WAS_PRESSED);

    return;
  }

  /* enable OneShot keys */
  OneShot.inject(OSM(LeftAlt), keyState);
  OneShot.inject(OSM(LeftShift), keyState);
  OneShot.inject(OSM(LeftControl), keyState);
}

static void oneShotMehBMacro(uint8_t keyState) {
  /* disable OneShot sticky keys */
  if (
    keyToggledOn(keyState) &&
    OneShot.isActive() &&
    OneShot.isSticky(OSM(LeftShift)) &&
    OneShot.isSticky(OSM(LeftAlt)) &&
    OneShot.isSticky(OSM(LeftGui))
  ) {
    OneShot.inject(OSM(LeftGui), IS_PRESSED);
    OneShot.inject(OSM(LeftGui), WAS_PRESSED);

    OneShot.inject(OSM(LeftAlt), IS_PRESSED);
    OneShot.inject(OSM(LeftAlt), WAS_PRESSED);

    OneShot.inject(OSM(LeftShift), IS_PRESSED);
    OneShot.inject(OSM(LeftShift), WAS_PRESSED);

    return;
  }

  /* enable OneShot sticky keys */
  if (OneShot.isActive() && keyToggledOn(keyState)) {
    OneShot.inject(OSM(LeftGui), IS_PRESSED);
    OneShot.inject(OSM(LeftGui), WAS_PRESSED);
    OneShot.inject(OSM(LeftGui), IS_PRESSED);
    OneShot.inject(OSM(LeftGui), WAS_PRESSED);

    OneShot.inject(OSM(LeftAlt), IS_PRESSED);
    OneShot.inject(OSM(LeftAlt), WAS_PRESSED);
    OneShot.inject(OSM(LeftAlt), IS_PRESSED);
    OneShot.inject(OSM(LeftAlt), WAS_PRESSED);

    OneShot.inject(OSM(LeftShift), IS_PRESSED);
    OneShot.inject(OSM(LeftShift), WAS_PRESSED);
    OneShot.inject(OSM(LeftShift), IS_PRESSED);
    OneShot.inject(OSM(LeftShift), WAS_PRESSED);

    return;
  }

  /* enable OneShot keys */
  OneShot.inject(OSM(LeftGui), keyState);
  OneShot.inject(OSM(LeftAlt), keyState);
  OneShot.inject(OSM(LeftShift), keyState);
}

static void oneShotMehCMacro(uint8_t keyState) {
  /* disable OneShot sticky keys */
  if (
    keyToggledOn(keyState) &&
    OneShot.isActive() &&
    OneShot.isSticky(OSM(LeftShift)) &&
    OneShot.isSticky(OSM(LeftControl)) &&
    OneShot.isSticky(OSM(LeftGui))
  ) {
    OneShot.inject(OSM(LeftGui), IS_PRESSED);
    OneShot.inject(OSM(LeftGui), WAS_PRESSED);

    OneShot.inject(OSM(LeftShift), IS_PRESSED);
    OneShot.inject(OSM(LeftShift), WAS_PRESSED);

    OneShot.inject(OSM(LeftControl), IS_PRESSED);
    OneShot.inject(OSM(LeftControl), WAS_PRESSED);

    return;
  }

  /* enable OneShot sticky keys */
  if (OneShot.isActive() && keyToggledOn(keyState)) {
    OneShot.inject(OSM(LeftGui), IS_PRESSED);
    OneShot.inject(OSM(LeftGui), WAS_PRESSED);
    OneShot.inject(OSM(LeftGui), IS_PRESSED);
    OneShot.inject(OSM(LeftGui), WAS_PRESSED);

    OneShot.inject(OSM(LeftShift), IS_PRESSED);
    OneShot.inject(OSM(LeftShift), WAS_PRESSED);
    OneShot.inject(OSM(LeftShift), IS_PRESSED);
    OneShot.inject(OSM(LeftShift), WAS_PRESSED);

    OneShot.inject(OSM(LeftControl), IS_PRESSED);
    OneShot.inject(OSM(LeftControl), WAS_PRESSED);
    OneShot.inject(OSM(LeftControl), IS_PRESSED);
    OneShot.inject(OSM(LeftControl), WAS_PRESSED);

    return;
  }

  /* enable OneShot keys */
  OneShot.inject(OSM(LeftGui), keyState);
  OneShot.inject(OSM(LeftShift), keyState);
  OneShot.inject(OSM(LeftControl), keyState);
}

static void oneShotMehDMacro(uint8_t keyState) {
  /* disable OneShot sticky keys */
  if (
    keyToggledOn(keyState) &&
    OneShot.isActive() &&
    OneShot.isSticky(OSM(LeftControl)) &&
    OneShot.isSticky(OSM(LeftAlt)) &&
    OneShot.isSticky(OSM(LeftGui))
  ) {
    OneShot.inject(OSM(LeftGui), IS_PRESSED);
    OneShot.inject(OSM(LeftGui), WAS_PRESSED);

    OneShot.inject(OSM(LeftAlt), IS_PRESSED);
    OneShot.inject(OSM(LeftAlt), WAS_PRESSED);

    OneShot.inject(OSM(LeftControl), IS_PRESSED);
    OneShot.inject(OSM(LeftControl), WAS_PRESSED);

    return;
  }

  /* enable OneShot sticky keys */
  if (OneShot.isActive() && keyToggledOn(keyState)) {
    OneShot.inject(OSM(LeftGui), IS_PRESSED);
    OneShot.inject(OSM(LeftGui), WAS_PRESSED);
    OneShot.inject(OSM(LeftGui), IS_PRESSED);
    OneShot.inject(OSM(LeftGui), WAS_PRESSED);

    OneShot.inject(OSM(LeftAlt), IS_PRESSED);
    OneShot.inject(OSM(LeftAlt), WAS_PRESSED);
    OneShot.inject(OSM(LeftAlt), IS_PRESSED);
    OneShot.inject(OSM(LeftAlt), WAS_PRESSED);

    OneShot.inject(OSM(LeftControl), IS_PRESSED);
    OneShot.inject(OSM(LeftControl), WAS_PRESSED);
    OneShot.inject(OSM(LeftControl), IS_PRESSED);
    OneShot.inject(OSM(LeftControl), WAS_PRESSED);

    return;
  }

  /* enable OneShot keys */
  OneShot.inject(OSM(LeftGui), keyState);
  OneShot.inject(OSM(LeftAlt), keyState);
  OneShot.inject(OSM(LeftControl), keyState);
}

static void oneShotCmdCtrlMacro(uint8_t keyState) {
  /* disable OneShot sticky keys */
  if (
    keyToggledOn(keyState) &&
    OneShot.isActive() &&
    OneShot.isSticky(OSM(LeftControl)) &&
    OneShot.isSticky(OSM(LeftGui))
  ) {
    OneShot.inject(OSM(LeftGui), IS_PRESSED);
    OneShot.inject(OSM(LeftGui), WAS_PRESSED);

    OneShot.inject(OSM(LeftControl), IS_PRESSED);
    OneShot.inject(OSM(LeftControl), WAS_PRESSED);

    return;
  }

  /* enable OneShot sticky keys */
  if (OneShot.isActive() && keyToggledOn(keyState)) {
    OneShot.inject(OSM(LeftGui), IS_PRESSED);
    OneShot.inject(OSM(LeftGui), WAS_PRESSED);
    OneShot.inject(OSM(LeftGui), IS_PRESSED);
    OneShot.inject(OSM(LeftGui), WAS_PRESSED);

    OneShot.inject(OSM(LeftControl), IS_PRESSED);
    OneShot.inject(OSM(LeftControl), WAS_PRESSED);
    OneShot.inject(OSM(LeftControl), IS_PRESSED);
    OneShot.inject(OSM(LeftControl), WAS_PRESSED);

    return;
  }

  /* enable OneShot keys */
  OneShot.inject(OSM(LeftGui), keyState);
  OneShot.inject(OSM(LeftControl), keyState);
}


/** macroAction dispatches keymap events that are tied to a macro
    to that macro. It takes two uint8_t parameters.

    The first is the macro being called (the entry in the 'enum' earlier in this file).
    The second is the state of the keyswitch. You can use the keyswitch state to figure out
    if the key has just been toggled on, is currently pressed or if it's just been released.

    The 'switch' statement should have a 'case' for each entry of the macro enum.
    Each 'case' statement should call out to a function to handle the macro in question.

 */

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {

  case MACRO_FAT_ARROW:
    if (keyToggledOn(keyState)) {
      return Macros.type(PSTR("=>"));
    }
    break;

  case MACRO_HYPER:
    oneShotHyperMacro(keyState);
    break;

  case MACRO_MEHA:
    oneShotMehAMacro(keyState);
    break;

  case MACRO_MEHB:
    oneShotMehBMacro(keyState);
    break;

  case MACRO_MEHC:
    oneShotMehCMacro(keyState);
    break;

  case MACRO_MEHD:
    oneShotMehDMacro(keyState);
    break;

  case MACRO_CMD_CTRL:
    oneShotCmdCtrlMacro(keyState);
    break;

  case MACRO_VERSION_INFO:
    versionInfoMacro(keyState);
    break;

  case MACRO_ANY:
    anyKeyMacro(keyState);
    break;
  }
  return MACRO_NONE;
}

// These 'solid' color effect definitions define a rainbow of
// LED color modes calibrated to draw 500mA or less on the
// Keyboardio Model 01.

static kaleidoscope::LEDSolidColor solidWhite(160, 160, 160);
static kaleidoscope::LEDSolidColor solidRed(160, 0, 0);
static kaleidoscope::LEDSolidColor solidOrange(140, 70, 0);
static kaleidoscope::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::LEDSolidColor solidGreen(0, 160, 0);
static kaleidoscope::LEDSolidColor solidBlue(0, 70, 130);
static kaleidoscope::LEDSolidColor solidIndigo(0, 0, 170);
static kaleidoscope::LEDSolidColor solidViolet(130, 0, 120);

/** toggleLedsOnSuspendResume toggles the LEDs off when the host goes to sleep,
 * and turns them back on when it wakes up.
 */
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

/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
void hostPowerManagementEventHandler(kaleidoscope::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}

/** This 'enum' is a list of all the magic combos used by the Model 01's
 * firmware The names aren't particularly important. What is important is that
 * each is unique.
 *
 * These are the names of your magic combos. They will be used by the
 * `USE_MAGIC_COMBOS` call below.
 */
enum {
  // Toggle between Boot (6-key rollover; for BIOSes and early boot) and NKRO
  // mode.
  COMBO_TOGGLE_NKRO_MODE
};

/** A tiny wrapper, to be used by MagicCombo.
 * This simply toggles the keyboard protocol via USBQuirks, and wraps it within
 * a function with an unused argument, to match what MagicCombo expects.
 */
static void toggleKeyboardProtocol(uint8_t combo_index) {
  USBQuirks.toggleKeyboardProtocol();
}

/** Magic combo list, a list of key combo and action pairs the firmware should
 * recognise.
 */
USE_MAGIC_COMBOS({.action = toggleKeyboardProtocol,
                  // Left Fn + Esc + Shift
                  .keys = { R3C6, R2C6, R3C7 }
                 });

// First, tell Kaleidoscope which plugins you want to use.
// The order can be important. For example, LED effects are
// added in the order they're listed here.
KALEIDOSCOPE_INIT_PLUGINS(
  // The boot greeting effect pulses the LED button for 10 seconds after the keyboard is first connected
  BootGreetingEffect,

  // The hardware test mode, which can be invoked by tapping Prog, LED and the left Fn button at the same time.
  TestMode,

  // LEDControl provides support for other LED modes
  LEDControl,

  // We start with the LED effect that turns off all the LEDs.
  LEDOff,

  // These static effects turn your keyboard's LEDs a variety of colors
  solidIndigo, solidViolet, solidWhite, solidGreen, solidRed, solidOrange, solidYellow,

  // The stalker effect lights up the keys you've pressed recently
  StalkerEffect,

  // The numpad plugin is responsible for lighting up the 'numpad' mode
  // with a custom LED effect
  NumPad,

  // The macros plugin adds support for macros
  Macros,

  // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
  MouseKeys,

  // The HostPowerManagement plugin allows us to turn LEDs off when then host
  // goes to sleep, and resume them when it wakes up.
  HostPowerManagement,

  // The MagicCombo plugin lets you use key combinations to trigger custom
  // actions - a bit like Macros, but triggered by pressing multiple keys at the
  // same time.
  MagicCombo,

  // The USBQuirks plugin lets you do some things with USB that we aren't
  // comfortable - or able - to do automatically, but can be useful
  // nevertheless. Such as toggling the key report protocol between Boot (used
  // by BIOSes) and Report (NKRO).
  USBQuirks,

  // Add plugins for custom mappings
  OneShot,
  EscapeOneShot,
  ActiveModColorEffect,
  TopsyTurvy
);

/** The 'setup' function is one of the two standard Arduino sketch functions.
 * It's called when your keyboard first powers up. This is where you set up
 * Kaleidoscope and any plugins.
 */
void setup() {
  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();

  // Set color for ActiveModColorEffect
  ActiveModColorEffect.highlight_color = CRGB(0x00, 0xff, 0xff);

  // While we hope to improve this in the future, the NumPad plugin
  // needs to be explicitly told which keymap layer is your numpad layer
  NumPad.numPadLayer = NUMPAD;

  // The LED Stalker mode has a few effects. The one we like is
  // called 'BlazingTrail'. For details on other options,
  // see https://github.com/keyboardio/Kaleidoscope-LED-Stalker
  StalkerEffect.variant = STALKER(BlazingTrail);

  // We want to make sure that the firmware starts with LED effects off
  // This avoids over-taxing devices that don't have a lot of power to share
  // with USB devices
  LEDOff.activate();
}

/** loop is the second of the standard Arduino sketch functions.
  * As you might expect, it runs in a loop, never exiting.
  *
  * For Kaleidoscope-based keyboard firmware, you usually just want to
  * call Kaleidoscope.loop(); and not do anything custom here.
  */

void loop() {
  Kaleidoscope.loop();
}
