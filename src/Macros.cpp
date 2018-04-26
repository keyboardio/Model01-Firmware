// -*- mode: c++ -*-

#include "Macros.h"
#include "Timekeeper.h"
#include <Kaleidoscope.h>
#include <Kaleidoscope-Macros.h>

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

void typeDateMacro(uint8_t keyState) {
  if (!keyToggledOn(keyState)) {
    return;
  }
#if KALEIDOSCOPE_INCLUDE_TIMEKEEPER
  jj::Timekeeper::typeCurrentDate();
#endif
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

#if KALEIDOSCOPE_INCLUDE_TIMEKEEPER
  case MACRO_TIMEKEEPER:
    jj::Macros::typeDateMacro(keyState);
    break;
#endif

  }
  return MACRO_NONE;
}



