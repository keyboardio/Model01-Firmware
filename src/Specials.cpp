// -*- mode: c++ -*-

#include "config.h"

#include "Specials.h"
#include <Kaleidoscope-HostOS.h>
#include <Kaleidoscope-Macros.h>
#if KALEIDOSCOPE_INCLUDE_EMOJI
# include <Kaleidoscope-Emoji.h>
#endif
#if KALEIDOSCOPE_INCLUDE_TIMEKEEPER
# include <Kaleidoscope-Timekeeper.h>
#endif


namespace jj {
namespace Specials {
namespace {

}
}
}


namespace jj {
namespace Specials {

void configure(void) {
}

void selectInputSourceUS(void) {
  if (::HostOS.os() != kaleidoscope::hostos::OSX) {
    return;
  }
  ::Macros.play(MACRO(D(LeftShift), D(LeftAlt), D(LeftGui), T(U), U(LeftShift), U(LeftAlt), U(LeftGui)));
}

void selectInputSourceUnicode(void) {
  if (::HostOS.os() != kaleidoscope::hostos::OSX) {
    return;
  }
  ::Macros.play(MACRO(D(LeftShift), D(LeftAlt), D(LeftGui), T(H), U(LeftShift), U(LeftAlt), U(LeftGui)));
}

namespace {


} // namespace
} // namespace Specials
} // namespacce jj


void emojiTypingWillStart() {
  jj::Specials::selectInputSourceUnicode();
}

void emojiTypingDidFinish() {
  jj::Specials::selectInputSourceUS();
}