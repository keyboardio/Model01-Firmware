// -*- mode: c++ -*-

#include "config.h"

#include <Kaleidoscope.h>
#include <Kaleidoscope-LangPack-German.h>

#if KALEIDOSCOPE_INCLUDE_TIMEKEEPER
# include <Kaleidoscope-Timekeeper.h>
#endif

#include "System.h"
#include "LEDControl.h"
#include "Macros.h"
#include "Leader.h"
#include "Qukeys.h"
#include "Emoji.h"

#include "keymaps.h"


void setup() {
  Serial.begin(9600);

  Kaleidoscope.setup();

  jj::Qukeys::configure();
  jj::System::configure();
  jj::Macros::configure();
  jj::Leader::configure();
  jj::LEDControl::configure();
  jj::Emoji::configure();

  Kaleidoscope.use(
#if KALEIDOSCOPE_INCLUDE_TIMEKEEPER
    &Timekeeper,
#endif
    &German
  );

}

void loop() {
  Kaleidoscope.loop();
}
