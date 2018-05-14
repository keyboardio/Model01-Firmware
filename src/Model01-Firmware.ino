// -*- mode: c++ -*-


#include <Kaleidoscope.h>
#include "System.h"
#include "LEDControl.h"
#include "Macros.h"
#include "Leader.h"
#include "Qukeys.h"
#include "Specials.h"

#include "keymaps.h"

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
