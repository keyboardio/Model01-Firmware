// -*- mode: c++ -*-

#include "LEDControl.h"
#include "config.h"
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
#include <LED-Off.h>

#if KALEIDOSCOPE_INCLUDE_HEATMAP
# include <Kaleidoscope-Heatmap.h>
#endif


namespace jj {
namespace LEDControl {
namespace {

}
}
}


namespace jj {
namespace LEDControl {

static kaleidoscope::LEDSolidColor solidRed(160, 0, 0);
static kaleidoscope::LEDSolidColor solidOrange(140, 70, 0);
static kaleidoscope::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::LEDSolidColor solidGreen(0, 160, 0);
static kaleidoscope::LEDSolidColor solidBlue(0, 70, 130);
static kaleidoscope::LEDSolidColor solidIndigo(0, 0, 170);
static kaleidoscope::LEDSolidColor solidViolet(130, 0, 120);

void configure(void) {

  Kaleidoscope.use(
    &::BootGreetingEffect,
    &::LEDControl,
    &::LEDToggle,
    &::LEDOff,

#if KALEIDOSCOPE_INCLUDE_HEATMAP
    &::HeatmapEffect,
#endif

#if KALEIDOSCOPE_INCLUDE_MORE_LED_EFFECTS
    &::ActiveModColorEffect,
    &::LEDRainbowEffect,
    &::LEDRainbowWaveEffect,
    &::LEDChaseEffect,
    &::LEDBreatheEffect,
    &::AlphaSquareEffect,
    &::StalkerEffect,
    &::LEDDigitalRainEffect,
    &solidRed, &solidOrange, &solidYellow, &solidGreen, &solidBlue, &solidIndigo, &solidViolet
#else
    &::ActiveModColorEffect,
    &::LEDBreatheEffect,
    &::LEDDigitalRainEffect,
    &solidIndigo,
#endif
  );

  ::BootGreetingEffect.search_key = Key_LEDToggle;

#if KALEIDOSCOPE_INCLUDE_MORE_LED_EFFECTS
  ::AlphaSquare.color = CRGB(255, 0, 0);
  ::LEDRainbowEffect.brightness(150); // 0-255
  ::LEDRainbowWaveEffect.brightness(150); // 0-255
  ::StalkerEffect.variant = STALKER(BlazingTrail);
#endif

  ::LEDOff.activate();
}

void pauseLEDs(void) {
  ::LEDControl.paused = true;
  ::LEDControl.set_all_leds_to({0, 0, 0});
  ::LEDControl.syncLeds();
}

void unpauseLEDs(void) {
  ::LEDControl.paused = false;
  ::LEDControl.refreshAll();
}

namespace {


} // namespace
} // namespace LEDConfig
} // namespacce jj




