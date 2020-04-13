// -*- mode: c++ -*-

#include "config.h"

#include <Kaleidoscope.h>
#include <Kaleidoscope-Leader.h>
#include <Kaleidoscope-Macros.h>
#include <Kaleidoscope-TapDance.h>
#include <Kaleidoscope-OneShot.h>
#include <Kaleidoscope-HostOS.h>
#include <Kaleidoscope-HostPowerManagement.h>
#include <Kaleidoscope-Escape-OneShot.h>
#include <Kaleidoscope-MouseKeys.h>
#include <Kaleidoscope-OneShot.h>
#include <Kaleidoscope-LangPack-German.h>
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
#include <Kaleidoscope-HardwareTestMode.h>

#include "System.h"
#include "LEDControl.h"
#include "Macros.h"
#include "TapDance.h"
#include "Leader.h"
#include "Specials.h"
#include "OneShot.h"

#include "keymaps.h"

KALEIDOSCOPE_INIT_PLUGINS(
#if KALEIDOSCOPE_INCLUDE_TEST_MODE
  HardwareTestMode,
#endif
  OneShot,
  EscapeOneShot,
  MouseKeys,
  HostOS,
  HostPowerManagement,
  Macros,
  TapDance,
  Leader,
  BootGreetingEffect,
  LEDControl,
  LEDOff,
  LEDToggle,
  ActiveModColorEffect,
  jj::LEDControl::solidBrightRed,
  jj::LEDControl::solidRed,
  jj::LEDControl::solidIndigo,
  LEDBreatheEffect,
  jj::LEDControl::solidPaleWhite,
  LEDDigitalRainEffect,
#if KALEIDOSCOPE_INCLUDE_MORE_LED_EFFECTS
  LEDRainbowEffect,
  LEDRainbowWaveEffect,
  LEDChaseEffect,
  AlphaSquareEffect,
  StalkerEffect,
  jj::LEDControl::solidOrange,
  jj::LEDControl::solidYellow,
  jj::LEDControl::solidGreen,
  jj::LEDControl::solidBlue,
  jj::LEDControl::solidViolet,
#endif
  German
);

void setup() {
  Kaleidoscope.setup();

  jj::System::configure();
  jj::Macros::configure();
  jj::TapDance::configure();
  jj::Leader::configure();
  jj::OneShot::configure();
  jj::LEDControl::configure();
  jj::Specials::configure();
}

void loop() {
  Kaleidoscope.loop();
}
