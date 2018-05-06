// -*- mode: c++ -*-

#include "Macros.h"
#include <Kaleidoscope-HostOS.h>

#include "config.h"

namespace jj {
namespace Macros {
namespace {

}
}
}


namespace jj {
namespace Macros {

void configure(void) {
  Kaleidoscope.use(&::Macros);
}

void versionInfoMacro(uint8_t keyState) {
  if (!keyToggledOn(keyState)) {
    return;
  }
  ::Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope "));
  ::Macros.type(PSTR(BUILD_INFORMATION));
}

void anyKeyMacro(uint8_t keyState) {
  static Key lastKey;
  if (keyToggledOn(keyState)) {
    lastKey.keyCode = Key_A.keyCode + (uint8_t)(millis() % 36);
  }

  if (keyIsPressed(keyState)) {
    kaleidoscope::hid::pressKey(lastKey);
  }
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
} // namespace Macros
} // namespacce jj


// ToDo: possible? or needed in .ino?
const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {

  case MACRO_VERSION_INFO:
    jj::Macros::versionInfoMacro(keyState);
    break;

  case MACRO_ANY:
    jj::Macros::anyKeyMacro(keyState);
    break;

  }
  return MACRO_NONE;
}



