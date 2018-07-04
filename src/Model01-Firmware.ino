// -*- mode: c++ -*-

#include "config.h"

#include <Kaleidoscope.h>
#include <Kaleidoscope-Qukeys.h>
#include <Kaleidoscope-Leader.h>
#include <Kaleidoscope-LEDToggle.h>
#include <Kaleidoscope-Macros.h>
#include <Kaleidoscope-HostOS.h>
#include <Kaleidoscope/HostOS-select.h>
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
#include <LED-Off.h>
#include <Kaleidoscope-Model01-TestMode.h>

#if KALEIDOSCOPE_INCLUDE_EMOJI
# include <Kaleidoscope-Emoji.h>
#endif
#if KALEIDOSCOPE_INCLUDE_TIMEKEEPER
# include <Kaleidoscope-Timekeeper.h>
#endif

#include "System.h"
#include "LEDControl.h"
#include "Macros.h"
#include "Leader.h"
#include "Qukeys.h"
#include "Specials.h"

#include "keymaps.h"

KALEIDOSCOPE_INIT_PLUGINS(
#if KALEIDOSCOPE_INCLUDE_TEST_MODE
  TestMode,
#endif
#if KALEIDOSCOPE_INCLUDE_QUKEYS
  Qukeys,
#endif
  OneShot,
  EscapeOneShot,
  MouseKeys,
  HostOS,
  HostPowerManagement,
  Macros,
#if KALEIDOSCOPE_INCLUDE_LEADER
  Leader,
#endif
  BootGreetingEffect,
  LEDControl,
  LEDToggle,
  LEDOff,
  ActiveModColorEffect,
#if KALEIDOSCOPE_INCLUDE_HEATMAP
  HeatmapEffect,
#endif
#if KALEIDOSCOPE_INCLUDE_MORE_LED_EFFECTS
  LEDRainbowEffect,
  LEDRainbowWaveEffect,
  LEDChaseEffect,
  LEDBreatheEffect,
  AlphaSquareEffect,
  StalkerEffect,
  LEDDigitalRainEffect,
  jj::LEDControl::solidRed,
  jj::LEDControl::solidOrange,
  jj::LEDControl::solidYellow,
  jj::LEDControl::solidGreen,
  jj::LEDControl::solidBlue,
  jj::LEDControl::solidIndigo,
  jj::LEDControl::solidViolet,
#else
  jj::LEDControl::solidLowWhite,
  jj::LEDControl::solidRed,
  jj::LEDControl::solidIndigo,
  LEDBreatheEffect,
  LEDDigitalRainEffect,
#endif
#if KALEIDOSCOPE_INCLUDE_EMOJI
  Emoji,
#endif
#if KALEIDOSCOPE_INCLUDE_TIMEKEEPER
  Timekeeper,
#endif
  German
);

void setup() {
  Serial.begin(9600);

  Kaleidoscope.setup();

  jj::Qukeys::configure();
  jj::System::configure();
  jj::Macros::configure();
  jj::Leader::configure();
  jj::LEDControl::configure();
  jj::Specials::configure();
}

void loop() {
  Kaleidoscope.loop();
}
