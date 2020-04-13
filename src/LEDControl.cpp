// -*- mode: c++ -*-

#include "config.h"

#include "LEDControl.h"
#include <Kaleidoscope-LEDControl.h>
#include <Kaleidoscope-LEDToggle.h>
#include <Kaleidoscope-LED-ActiveModColor.h>
#include <Kaleidoscope-LED-AlphaSquare.h>
#include <Kaleidoscope-LED-Stalker.h>
#include <Kaleidoscope-LEDEffect-BootGreeting.h>
#include <Kaleidoscope-LEDEffect-Breathe.h>
#include <Kaleidoscope-LEDEffect-Chase.h>
#include <Kaleidoscope-LEDEffect-DigitalRain.h>
#include <Kaleidoscope-LEDEffect-Rainbow.h>
#include <Kaleidoscope-LEDEffect-SolidColor.h>


namespace jj {
namespace LEDControl {
namespace {

}
}
}


namespace jj {
namespace LEDControl {

void configure(void) {
  ::BootGreetingEffect.search_key = Key_LEDToggleOnOff;
  ::BootGreetingEffect.hue = 0;

  ::ActiveModColorEffect.highlight_color = CRGB(0x00, 0xff, 0xff);
  ::ActiveModColorEffect.sticky_color = CRGB(0xff, 0x00, 0xff);

#if KALEIDOSCOPE_INCLUDE_MORE_LED_EFFECTS
  ::AlphaSquare.color = CRGB(255, 0, 0);
  ::LEDRainbowEffect.brightness(150); // 0-255
  ::LEDRainbowWaveEffect.brightness(150); // 0-255
  ::StalkerEffect.variant = STALKER(BlazingTrail);
#endif

  ::LEDOff.activate();
}

void disable(void) {
  ::LEDControl.disable();
}

void enable(void) {
  ::LEDControl.enable();
}

namespace {


} // namespace
} // namespace LEDConfig
} // namespacce jj




