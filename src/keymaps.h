// -*- mode: c++ -*-

#pragma once

#include "config.h"
#include "layers.h"
#include "keydefs.h"

#include "Macros.h"
#include "TapDance.h"


// *INDENT-OFF*

KEYMAPS(

  [QWERTY] = KEYMAP_STACKED
  (___,          Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDToggle,
   Key_Backtick, Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
   Key_PageUp,   Key_A, Key_S, Key_D, Key_F, Key_G,
   Key_PageDown, Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,
   Key_LeftGui, Key_Backspace, Key_LeftControl, Key_LeftShift,
   ShiftToLayer(FUNCTION_JJ),

   JJ_Xcode,  Key_6, Key_7, Key_8,     Key_9,      Key_0,         Key_Minus,
   Key_Enter, Key_Y, Key_U, Key_I,     Key_O,      Key_P,         Key_Equals,
              Key_H, Key_J, Key_K,     Key_L,      Key_Semicolon, Key_Quote,
   JJ_Emoji,  Key_N, Key_M, Key_Comma, Key_Period, Key_Slash,     Key_Backslash,
   Key_RightShift, Key_LeftAlt, Key_Spacebar, Key_RightGui,
   ShiftToLayer(FUNCTION_JJ)),

  [FUNCTION_JJ] =  KEYMAP_STACKED
  (Key_CapsLock, Key_F1,     Key_F2,      Key_F3,     Key_F4,        Key_F5, Key_LEDToggleNext,
   Key_Tab,      ___,        Key_mouseUp, ___,        Key_mouseBtnR, ___,    Key_Enter,
   Key_Home,     Key_mouseL, Key_mouseDn, Key_mouseR, Key_mouseBtnL, ___,
   Key_End,      ___,        ___,         ___,        Key_mouseBtnM, ___,    Key_Spacebar,
   ___, Key_Delete, ___, ___,
   ___,

   ___,                     Key_F6,                   Key_F7,                   Key_F8,                   Key_F9,          Key_F10,          Key_Eszett,
   Consumer_PlaySlashPause, ___,                      Key_LeftCurlyBracket,     Key_RightCurlyBracket,    Key_LeftBracket, Key_RightBracket, Key_UUmlaut,
                            Key_LeftArrow,            Key_DownArrow,            Key_UpArrow,              Key_RightArrow,  Key_OUmlaut,      Key_AUmlaut,
   ___,                     TD(TAP_DANCE_NEXT_TRACK), Consumer_VolumeDecrement, Consumer_VolumeIncrement, JJ_TypeDate,     ___,              ___,
   ___, ___, Key_Enter, ___,
   ___),

#if KALEIDOSCOPE_INCLUDE_FUNCTION_ORIGINAL
  [FUNCTION_ORIGINAL] =  KEYMAP_STACKED
  (___,      Key_F1,           Key_F2,      Key_F3,     Key_F4,        Key_F5,           XXX,
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
#endif

#if KALEIDOSCOPE_INCLUDE_XCODE
  [XCODE] =  KEYMAP_STACKED
  (___,               Key_1,        Key_2,       Key_3,        Key_4,                  Key_5,              Key_LEDToggle,
   Key_Backtick,      Key_Q,        Key_W,       Key_E,        JJ_XcodeFindAndReplace, Key_T,              Key_Tab,
   JJ_XcodePaste,     Key_A,        Key_S,       Key_D,        JJ_XcodeFind,           JJ_XcodeNextResult,
   JJ_XcodeCopyOrCut, JJ_XcodeUndo, JJ_XcodeCut, JJ_XcodeCopy, JJ_XcodePaste,          Key_B,              ___,
   Key_LeftGui, Key_Backspace, Key_LeftControl, Key_LeftShift,
   ShiftToLayer(FUNCTION_JJ),

   UnlockLayer(XCODE), Key_6,                Key_7,                Key_8,              Key_9,                   Key_0,         Key_Minus,
   Key_Enter,          Key_Y,                Key_U, Key_I,         JJ_XcodeQuickOpen,  Key_P,                   Key_Equals,
                       JJ_XcodeNavigateBack, JJ_XcodeNavigateDown, JJ_XcodeNavigateUp, JJ_XcodeNavigateForward, Key_Semicolon, Key_Quote,
   JJ_Emoji,           Key_N,                Key_M,                Key_Comma,          Key_Period,              Key_Slash,     Key_Backslash,
   Key_RightShift, Key_LeftAlt, Key_Spacebar, Key_RightGui,
   ShiftToLayer(FUNCTION_JJ)),
#endif

#if KALEIDOSCOPE_INCLUDE_EMOJI
  [EMOJI] =  KEYMAP_STACKED
  (Key_EmojiCricket, Key_EmojiUnicornFace,   Key_EmojiEyes,  Key_EmojiSparkles,    ___,                ___,               ___,
   ___,              Key_EmojiBalloon,       Key_EmojiWave,  Key_EmojiFlushed,     Key_EmojiRocket,    Key_EmojiMetal,    ___,
   ___,              Key_EmojiWarning,       Key_EmojiBlush, Key_EmojiThumbsdown,  Key_EmojiSunflower, Key_EmojiGrimaced,
   ___,              Key_EmojiExplodingHead, Key_EmojiPeach, Key_EmojiCrazy,       Key_EmojiVulcan,    Key_EmojiBoom,     ___,
   ___, ___, ___, ___,
   ___,

   Key_EmojiUpsideDown, ___,                  ___,               ___,                  ___,                       Key_EmojiWhiteCheckMark, Key_EmojiCrossMark,
   ___,                 Key_EmojiDisbelief,   Key_EmojiThumbsup, Key_EmojiThinking,    Key_EmojiManDancing,       Key_EmojiParty,          ___,
                        Key_EmojiMischievous, Key_EmojiJoyful,   Key_EmojiFlirty,      Key_EmojiConfident,        Key_EmojiHole,           ___,
   Key_EmojiBlush,      Key_EmojiNerd,        Key_EmojiAnnoyed,  Key_EmojiWink,        Key_EmojiHourglassFlowing, Key_EmojiConstruction,   ___,
   ___, ___, ___, ___,
   ___),
#endif

	) // KEYMAPS(

// *INDENT-ON*