// -*- mode: c++ -*-

#include "config.h"

#include "Macros.h"
#include <Kaleidoscope.h>
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

static void versionInfoMacro(uint8_t keyState) {
  if (keyToggledOn(keyState)) {
    ::Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope "));
    ::Macros.type(PSTR(BUILD_INFORMATION));
  }
}

static void anyKeyMacro(uint8_t keyState) {
  static Key lastKey;
  bool toggledOn = false;
  if (keyToggledOn(keyState)) {
    lastKey.setKeyCode(Key_A.getKeyCode() + (uint8_t)(millis() % 36));
    toggledOn = true;
  }

  if (keyIsPressed(keyState))
    Kaleidoscope.hid().keyboard().pressKey(lastKey, toggledOn);
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



