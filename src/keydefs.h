// -*- mode: c++ -*-

/**
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/kaleidoscope/key_defs_keyboard.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/kaleidoscope/key_defs_consumerctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/kaleidoscope/key_defs_sysctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/kaleidoscope/key_defs_keymaps.h
  */

#pragma once

#include "config.h"
#include "layers.h"
#include "Macros.h"
#include "TapDance.h"


#if KALEIDOSCOPE_INCLUDE_XCODE
// Xcode Layer
# define JJ_Xcode OSL(XCODE)

// File Menu
# define JJ_XcodeNewEditor LCTRL(LGUI(Key_T))
# define JJ_XcodeNewEditorBelow LCTRL(LALT(LGUI(Key_T)))
# define JJ_XcodeOpenQuickly LSHIFT(LGUI(Key_O))
# define JJ_XcodeCloseEditor LCTRL(LALT(LGUI(Key_W)))
# define JJ_XcodeCloseOtherEditors LCTRL(LALT(LSHIFT(LGUI(Key_W))))

// Edit Menu
# define JJ_XcodeCopySymbolName LCTRL(LSHIFT(LGUI(Key_C)))
# define JJ_XcodeCopyQualifiedSymbolName LCTRL(LALT(LSHIFT(LGUI(Key_C))))

// View Menu
# define JJ_XcodeFocusEditor LCTRL(LSHIFT(LGUI(Key_Return)))
# define JJ_XcodeShowRelatedItems LCTRL(Key_1)
# define JJ_XcodeToggleCodeReview LALT(LSHIFT(LGUI(Key_Return)))
# define JJ_XcodeResetAssistantSelection LALT(LSHIFT(LGUI(Key_Z)))
# define JJ_XcodeActivateConsole LSHIFT(LGUI(Key_C))
# define JJ_XcodeToggleDebugArea LSHIFT(LGUI(Key_Y))
# define JJ_XcodeShowLibrary LSHIFT(LGUI(Key_L))

// Find Menu




# define JJ_XcodeQuickOpen LGUI(LSHIFT(Key_O))
# define JJ_XcodeNavigateBack LGUI(LCTRL(Key_LeftArrow))
# define JJ_XcodeNavigateForward LGUI(LCTRL(Key_RightArrow))
# define JJ_XcodeNavigateUp LGUI(LCTRL(Key_UpArrow))
# define JJ_XcodeNavigateDown LGUI(LCTRL(Key_DownArrow))
# define JJ_XcodeShowRelatedItems LCTRL(Key_1)
# define JJ_XcodeFindInFile LGUI(Key_F)
# define JJ_XcodeFindInProject LGUI(LSHIFT(Key_F))
# define JJ_XcodeFind TD(TAP_DANCE_XCODE_FIND)
# define JJ_XcodeFindAndReplaceInFile LGUI(LALT(Key_F))
# define JJ_XcodeFindAndReplaceInProject LGUI(LALT(LSHIFT(Key_F)))
# define JJ_XcodeFindAndReplace TD(TAP_DANCE_XCODE_FIND_AND_REPLACE)
# define JJ_XcodeNextResult LGUI(Key_G)
# define JJ_XcodeUndo LGUI(Key_Z)
# define JJ_XcodeCut LGUI(Key_X)
# define JJ_XcodeCopy LGUI(Key_C)
# define JJ_XcodePaste LGUI(Key_V)
# define JJ_XcodeCopyOrCut TD(TAP_DANCE_XCODE_COPY_OR_CUT)
# define JJ_XcodeSelectLine LGUI(LSHIFT(Key_E))
# define JJ_XcodeEditAll LGUI(LCTRL(Key_E))
# define JJ_XcodeShowCompletion LCTRL(Key_Space)
# define JJ_XcodeNextCompletion LCTRL(Key_Period)
# define JJ_XcodeCommentSelection LGUI(Key_Slash)
# define JJ_XcodeNextIssue LGUI(Key_Quote)
# define JJ_XcodePreviousIssue LGUI(LSHIFT(Key_Quote))
# define JJ_XcodeFixNextIssue LCTRL(LGUI(Key_Quote))
# define JJ_XcodeFixPreviousIssue LCTRL(LGUI(LSHIFT(Key_Quote)))
# define JJ_XcodeAddBreakpoint LGUI(Key_Backslash)
# define JJ_XcodeActivateBreakpoints LGUI(Key_Y)
#else
# define JJ_Xcode ___
#endif

