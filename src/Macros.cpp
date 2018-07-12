// -*- mode: c++ -*-

#include "config.h"

#include "Macros.h"
#include <Kaleidoscope-Macros.h>


namespace jj {
namespace Macros {
namespace {

}
}
}


namespace jj {
namespace Macros {

void configure(void) {

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

namespace {


} // namespace
} // namespace Macros
} // namespacce jj


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



