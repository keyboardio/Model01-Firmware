// -*- mode: c++ -*-

#pragma once

#include "config.h"
#include "layers.h"
#include "keydefs.h"

#include "Macros.h"
#include "TapDance.h"
#include "Leader.h"


// *INDENT-OFF*

KEYMAPS(

  [QWERTY] = KEYMAP_STACKED
  (Key_CapsLock, Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDToggle,
   Key_Backtick, Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
   Key_PageUp,   Key_A, Key_S, Key_D, Key_F, Key_G,
   Key_PageDown, Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,
   OSM(LeftGui), Key_Backspace, OSM(LeftControl), OSM(LeftShift),
   ShiftToLayer(FUNCTION_JJ),

   JJ_Xcode,   Key_6, Key_7, Key_8,     Key_9,      Key_0,         Key_Minus,
   Key_Enter,  Key_Y, Key_U, Key_I,     Key_O,      Key_P,         Key_Equals,
               Key_H, Key_J, Key_K,     Key_L,      Key_Semicolon, Key_Quote,
   LEAD(MAIN), Key_N, Key_M, Key_Comma, Key_Period, Key_Slash,     Key_Backslash,
   OSM(RightShift), OSM(LeftAlt), Key_Spacebar, OSM(RightGui),
   ShiftToLayer(FUNCTION_JJ)),

  [FUNCTION_JJ] =  KEYMAP_STACKED
  (Key_CapsLock, Key_F1,     Key_F2,      Key_F3,     Key_F4,        Key_F5, Key_LEDEffectNext,
   Key_Tab,      ___,        Key_mouseUp, ___,        Key_mouseBtnR, ___,    Key_Enter,
   Key_Home,     Key_mouseL, Key_mouseDn, Key_mouseR, Key_mouseBtnL, ___,
   Key_End,      ___,        ___,         ___,        ___,           ___,    Key_Spacebar,
   ___, Key_Delete, ___, ___,
   ___,

   ___,                     Key_F6,                   Key_F7,                   Key_F8,                   Key_F9,          Key_F10,          Key_Eszett,
   Consumer_PlaySlashPause, ___,                      Key_LeftCurlyBracket,     Key_RightCurlyBracket,    Key_LeftBracket, Key_RightBracket, Key_UUmlaut,
                            Key_LeftArrow,            Key_DownArrow,            Key_UpArrow,              Key_RightArrow,  Key_OUmlaut,      Key_AUmlaut,
   ___,                     TD(TAP_DANCE_NEXT_TRACK), Consumer_VolumeDecrement, Consumer_VolumeIncrement, ___,             ___,              ___,
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
   // unused: PROG, `, Z, X, ESC, 8, 9, I
  [XCODE] =  KEYMAP_STACKED
  (XXX,            JJ_XcodeShowRelatedItems,  JJ_XcodeCopySymbolName, JJ_XcodeCopyQualifiedSymbolName, JJ_XcodeFindCallHierarchy,         JJ_XcodeFindSelectedSymbolInWorkspace, JJ_XcodeMoveFocusToNextArea,
   XXX,            JJ_XcodeCloseOtherEditors, JJ_XcodeCloseEditor,    JJ_XcodeEditAllInScope,          JJ_XcodeFindAndReplaceInWorkspace, JJ_XcodeNewEditor,                     JJ_XcodeMoveFocusToNextEditor,
   JJ_XcodeCommit, JJ_XcodeShowCodeActions,   JJ_XcodeSelectLine,     JJ_XcodeJumpToDefinition,        JJ_XcodeFindInWorkspace,           JJ_XcodeFindNextInWorkspace,
   JJ_XcodePull,   XXX,                       XXX,                    JJ_XcodeActivateConsole,         JJ_XcodeRefactorExtractToVariable, JJ_XcodeNewEditorBelow,                XXX,
   ___, ___, ___, ___,
   ___,

   ___,                 JJ_XcodeRevealInProjectNavigator, JJ_XcodeRevealInDebugNavigator,            XXX,                           XXX,                  JJ_XcodeShowLibrary,      JJ_XcodeUppercaseWord,
   JJ_XcodeAssistant,   JJ_XcodePauseContinue,            JJ_XcodeContinueToCurrentLine,             XXX,                           JJ_XcodeOpenQuickly,  JJ_XcodeShowSpelling,     JJ_XcodeCapitalizeWord,
                        JJ_XcodeGoBack,                   JJ_XcodeJumpToNextCounterpartInNextEditor, JJ_XcodeJumpToNextCounterpart, JJ_XcodeGoForward,    JJ_XcodeCheckSpelling,    JJ_XcodeLowercaseWord,
   JJ_XcodeFocusEditor, JJ_XcodeRefactorRename,           JJ_XcodeRefactorExtractToMethod,           JJ_XcodeMoveLineUp,            JJ_XcodeMoveLineDown, JJ_XcodeCommentSelection, JJ_XcodeJumpToNextChange,
   ___, ___, ___, ___,
   ___),
#endif

	) // KEYMAPS(

// *INDENT-ON*