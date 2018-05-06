// -*- mode: c++ -*-

#include "config.h"

#include <Kaleidoscope.h>
#include <Kaleidoscope-Emoji.h>
#include <Kaleidoscope-HostOS.h>
#include <Kaleidoscope/HostOS-select.h>
#include <Kaleidoscope-HostPowerManagement.h>
#include <Kaleidoscope-LangPack-German.h>
#include <Kaleidoscope-MouseKeys.h>
#include <Kaleidoscope-OneShot.h>
#include <Kaleidoscope-Escape-OneShot.h>
#if KALEIDOSCOPE_INCLUDE_TIMEKEEPER
# include <Kaleidoscope-Timekeeper.h>
#endif

#include "LEDControl.h"
#include "Macros.h"

#if KALEIDOSCOPE_INCLUDE_TEST_MODE
# include <Kaleidoscope-Model01-TestMode.h>
#endif

#include "keymaps.h"

void hostPowerManagementEventHandler(kaleidoscope::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::HostPowerManagement::Suspend:
    jj::LEDControl::pauseLEDs();
    break;
  case kaleidoscope::HostPowerManagement::Resume:
    jj::LEDControl::unpauseLEDs();
    break;
  case kaleidoscope::HostPowerManagement::Sleep:
    break;
  }
}

void emojiTypingWillStart() {
  jj::Macros::selectInputSourceUnicode();
}

void emojiTypingDidFinish() {
  jj::Macros::selectInputSourceUS();
}

void setup() {
  Serial.begin(9600);

  Kaleidoscope.setup();

  Kaleidoscope.use(
#if KALEIDOSCOPE_INCLUDE_TEST_MODE
    &TestMode,
#endif
#if KALEIDOSCOPE_INCLUDE_TIMEKEEPER
    &Timekeeper,
#endif
    &OneShot,
    &EscapeOneShot,
    &MouseKeys,
    &HostOS,
    &HostPowerManagement,
    &German
  );

  HostPowerManagement.enableWakeup();

  jj::Macros::configure();
  jj::LEDControl::configure();
}

void loop() {
  Kaleidoscope.loop();
}
