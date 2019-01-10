// -*- mode: c++ -*-

#include "config.h"

#include "OneShot.h"
#include <Kaleidoscope-OneShot.h>


namespace jj {
namespace OneShot {

void configure(void) {
  ::OneShot.enableStickablity();
  ::OneShot.time_out = 2500;
  ::OneShot.hold_time_out = 250;
  ::OneShot.double_tap_time_out = 250;
}

} // namespace OneShot
} // namespacce jj


