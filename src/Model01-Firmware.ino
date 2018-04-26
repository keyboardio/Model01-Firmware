// -*- mode: c++ -*-

#include "config.h"

#include <Kaleidoscope.h>
#include <Kaleidoscope-Emoji.h>
#include <Kaleidoscope-HostOS.h>
#include <Kaleidoscope/HostOS-select.h>
#include <Kaleidoscope-HostPowerManagement.h>
#include <Kaleidoscope-LangPack-German.h>
#include <Kaleidoscope-Macros.h>
#include <Kaleidoscope-MouseKeys.h>
#include <Kaleidoscope-OneShot.h>
#include <Kaleidoscope-Escape-OneShot.h>

#include <Kaleidoscope-LEDControl.h>
#include <Kaleidoscope-LEDToggle.h>
#include <Kaleidoscope-LED-AlphaSquare.h>
#include <Kaleidoscope-LED-Stalker.h>
#include <Kaleidoscope-LEDEffect-BootGreeting.h>
#include <Kaleidoscope-LEDEffect-Breathe.h>
#include <Kaleidoscope-LEDEffect-Chase.h>
#include <Kaleidoscope-LEDEffect-DigitalRain.h>
#include <Kaleidoscope-LEDEffect-Rainbow.h>
#include <Kaleidoscope-LEDEffect-SolidColor.h>
#include <LED-Off.h>

#include "Macros.h"
#if KALEIDOSCOPE_INCLUDE_TIMEKEEPER
# include "Timekeeper.h"
#endif

#if KALEIDOSCOPE_INCLUDE_TEST_MODE
# include <Kaleidoscope-Model01-TestMode.h>
#endif

#include "keymaps.h"


void selectInputSourceUS() {
  if (HostOS.os() != kaleidoscope::hostos::OSX) {
    return;
  }
  Macros.play(MACRO(D(LeftShift), D(LeftAlt), D(LeftGui), T(U), U(LeftShift), U(LeftAlt), U(LeftGui)));
}

void selectInputSourceUnicode() {
  if (HostOS.os() != kaleidoscope::hostos::OSX) {
    return;
  }
  Macros.play(MACRO(D(LeftShift), D(LeftAlt), D(LeftGui), T(H), U(LeftShift), U(LeftAlt), U(LeftGui)));
}

void toggleLedsOnSuspendResume(kaleidoscope::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::HostPowerManagement::Suspend:
    LEDControl.paused = true;
    LEDControl.set_all_leds_to({0, 0, 0});
    LEDControl.syncLeds();
    break;
  case kaleidoscope::HostPowerManagement::Resume:
    LEDControl.paused = false;
    LEDControl.refreshAll();
    break;
  case kaleidoscope::HostPowerManagement::Sleep:
    break;
  }
}

void hostPowerManagementEventHandler(kaleidoscope::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}


void emojiTypingWillStart() {
  selectInputSourceUnicode();
}

void emojiTypingDidFinish() {
  selectInputSourceUS();
}


static kaleidoscope::LEDSolidColor solidRed(160, 0, 0);
static kaleidoscope::LEDSolidColor solidOrange(140, 70, 0);
static kaleidoscope::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::LEDSolidColor solidGreen(0, 160, 0);
static kaleidoscope::LEDSolidColor solidBlue(0, 70, 130);
static kaleidoscope::LEDSolidColor solidIndigo(0, 0, 170);
static kaleidoscope::LEDSolidColor solidViolet(130, 0, 120);


void setup() {
  Serial.begin(9600);

  Kaleidoscope.setup();

  Kaleidoscope.use(
    &BootGreetingEffect,
#if KALEIDOSCOPE_INCLUDE_TEST_MODE
    &TestMode,
#endif
    &LEDControl,
    &LEDToggle,

    &LEDOff,
    &LEDRainbowEffect,
    &LEDRainbowWaveEffect,
    &LEDChaseEffect,
    &solidRed, &solidOrange, &solidYellow, &solidGreen, &solidBlue, &solidIndigo, &solidViolet,
    &LEDBreatheEffect,
    &AlphaSquareEffect,
    &StalkerEffect,
    &LEDDigitalRainEffect,

    &Macros,
    &OneShot,
    &EscapeOneShot,
    &MouseKeys,
    &HostOS,
    &HostPowerManagement,
    &German
  );

  jj::Macros::configure();
#if KALEIDOSCOPE_INCLUDE_TIMEKEEPER
  jj::Timekeeper::configure();
#endif

  AlphaSquare.color = CRGB(255, 0, 0);

  LEDRainbowEffect.brightness(150); // 0-255
  LEDRainbowWaveEffect.brightness(150); // 0-255

  StalkerEffect.variant = STALKER(BlazingTrail);

  HostPowerManagement.enableWakeup();

  LEDOff.activate();
}


void loop() {
  // Todo: move to plugin
  if (Serial.available()) {
    jj::Timekeeper::processSyncMessage();
  }

  Kaleidoscope.loop();

}
