// -*- mode: c++ -*-

#include "Emoji.h"
#include <Kaleidoscope-Emoji.h>
#include <Kaleidoscope-HostOS.h>
#include <Kaleidoscope-Macros.h>

#include "config.h"


namespace jj {
namespace Emoji {
namespace {

}
}
}


namespace jj {
namespace Emoji {

void configure(void) {
#if KALEIDOSCOPE_INCLUDE_EMOJI
  Kaleidoscope.use(&::Emoji);
#endif
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
} // namespace Emoji
} // namespacce jj


void emojiTypingWillStart() {
  jj::Emoji::selectInputSourceUnicode();
}

void emojiTypingDidFinish() {
  jj::Emoji::selectInputSourceUS();
}