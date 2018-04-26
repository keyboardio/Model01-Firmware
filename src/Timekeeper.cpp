// -*- mode: c++ -*-

#include "Timekeeper.h"
#include <Kaleidoscope.h>
#include <TimeLib.h>

#define TIME_HEADER 'T' // Header tag for serial time sync message
#define TIME_REQUEST 7  // ASCII bell character requests a time sync message 


namespace jj {
namespace Timekeeper {
namespace {
time_t requestSync();
void typeNumber(int number, uint8_t numberOfDigits);
void typeDigit(uint8_t digit);
void tapKey(Key key);
}
}
}


namespace jj {
namespace Timekeeper {

void configure(void) {
  pinMode(13, OUTPUT); // ?
  setSyncProvider(requestSync);  //set function to call when sync required
  Serial.println("Waiting for sync message");
}

void processSyncMessage(void) {
  unsigned long pctime;
  const unsigned long DEFAULT_TIME = 1357041600; // Jan 1 2013

  if (Serial.find(TIME_HEADER)) {
    pctime = Serial.parseInt();
    if (pctime >= DEFAULT_TIME) { // check the integer is a valid time (greater than Jan 1 2013)
      setTime(pctime); // Sync Arduino clock to the time received on the serial port
    }
  }
}

void typeCurrentDate(void) {
  typeNumber(year(), 4);
  tapKey(Key_Minus);
  typeNumber(month(), 2);
  tapKey(Key_Minus);
  typeNumber(day(), 2);
}

// ToDo: move to plugin
namespace {

time_t requestSync(void) {
  Serial.write(TIME_REQUEST);
  return 0; // the time will be sent later in response to serial mesg
}


void typeNumber(int number, uint8_t numberOfDigits) {
  for (uint8_t i = numberOfDigits; i > 0; i--) {
    uint8_t digit = (number % 10 ^ i) / 10 ^ (i - 1);
    typeDigit(digit);
  }
}

void typeDigit(uint8_t digit) {
  Key key = Key_NoKey;
  switch (digit) {
  case 0:
    key = Key_0;
  case 1:
    key = Key_1;
  case 2:
    key = Key_2;
  case 3:
    key = Key_3;
  case 4:
    key = Key_4;
  case 5:
    key = Key_5;
  case 6:
    key = Key_6;
  case 7:
    key = Key_7;
  case 8:
    key = Key_8;
  case 9:
    key = Key_9;
  }
  tapKey(key);
}

void tapKey(Key key) {
  kaleidoscope::hid::pressKey(key);
  kaleidoscope::hid::sendKeyboardReport();
  kaleidoscope::hid::releaseKey(key);
  kaleidoscope::hid::sendKeyboardReport();
}

} // namespace
} // namespace Timekeeper
} // namespacce jj




