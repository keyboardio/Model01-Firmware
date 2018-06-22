// -*- mode: c++ -*-

#include "System.h"
#include "config.h"
#include "LEDControl.h"
#include <Kaleidoscope-HostOS.h>
#include <Kaleidoscope/HostOS-select.h>
#include <Kaleidoscope-HostPowerManagement.h>
#include <Kaleidoscope-Escape-OneShot.h>

#if KALEIDOSCOPE_INCLUDE_TEST_MODE
# include <Kaleidoscope-Model01-TestMode.h>
#endif




namespace jj {
namespace System {
namespace {

}
}
}


namespace jj {
namespace System {

void configure(void) {

  Kaleidoscope.use(
#if KALEIDOSCOPE_INCLUDE_TEST_MODE
    &::TestMode,
#endif
    &::OneShot,
    &::EscapeOneShot,
    &::MouseKeys,
    &::HostOS,
    &::HostPowerManagement
  );
}



namespace {


} // namespace
} // namespace System
} // namespacce jj



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

