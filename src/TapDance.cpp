// -*- mode: c++ -*-

#include "config.h"

#include "TapDance.h"
#include <Kaleidoscope-TapDance.h>
#include <Kaleidoscope-OneShot.h>

#include "keydefs.h"

namespace jj {
namespace TapDance {
namespace {

}
}
}


namespace jj {
namespace TapDance {

void configure(void) {

}

namespace {

} // namespace
} // namespace TapDance
} // namespacce jj


void tapDanceAction(uint8_t tap_dance_index, byte row, byte col, uint8_t tap_count, kaleidoscope::TapDance::ActionType tap_dance_action) {
  switch (tap_dance_index) {
  case TAP_DANCE_LEFT_SHIFT:
    return tapDanceActionKeys(tap_count, tap_dance_action, Key_LeftShift, Key_CapsLock);
  case TAP_DANCE_RIGHT_SHIFT:
    return tapDanceActionKeys(tap_count, tap_dance_action, Key_RightShift, Key_CapsLock);
  case TAP_DANCE_NEXT_TRACK:
    return tapDanceActionKeys(tap_count, tap_dance_action, Consumer_ScanNextTrack, Consumer_ScanPreviousTrack);
#if KALEIDOSCOPE_INCLUDE_XCODE
  case TAP_DANCE_TOGGLE_XCODE:
    return tapDanceActionKeys(tap_count, tap_dance_action, JJ_OneShotXcode, JJ_ToggleXcode);
  case TAP_DANCE_XCODE_FIND:
    return tapDanceActionKeys(tap_count, tap_dance_action, JJ_XcodeFindInFile, JJ_XcodeFindInProject);
  case TAP_DANCE_XCODE_FIND_AND_REPLACE:
    return tapDanceActionKeys(tap_count, tap_dance_action, JJ_XcodeFindAndReplaceInFile, JJ_XcodeFindAndReplaceInProject);
  case TAP_DANCE_XCODE_COPY_OR_CUT:
    return tapDanceActionKeys(tap_count, tap_dance_action, JJ_XcodeCopy, JJ_XcodeCut);
#endif
  }
}




