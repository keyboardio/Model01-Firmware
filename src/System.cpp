// -*- mode: c++ -*-

#include "config.h"

#include "System.h"
#include "LEDControl.h"
#include <Kaleidoscope-HostPowerManagement.h>
#include <Kaleidoscope-HostOS.h>


namespace jj {
namespace System {
namespace {

}
}
}


namespace jj {
namespace System {

void configure(void) {
#if !KALEIDOSCOPE_HOSTOS_GUESSER
  ::HostOS.os(kaleidoscope::hostos::OSX);
#endif
}



namespace {


} // namespace
} // namespace System
} // namespacce jj



void hostPowerManagementEventHandler(kaleidoscope::plugin::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::plugin::HostPowerManagement::Suspend:
    jj::LEDControl::pauseLEDs();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Resume:
    jj::LEDControl::unpauseLEDs();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Sleep:
    break;
  }
}

