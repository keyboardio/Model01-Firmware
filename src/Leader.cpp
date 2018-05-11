// -*- mode: c++ -*-

#include "Leader.h"
#include "config.h"
#if KALEIDOSCOPE_INCLUDE_LEADER
# include <Kaleidoscope-Leader.h>
#endif


namespace jj {
namespace Leader {
namespace {

}
}
}


namespace jj {
namespace Leader {

void configure(void) {
#if KALEIDOSCOPE_INCLUDE_LEADER
  Kaleidoscope.use(&::Leader);
#endif
}



namespace {


} // namespace
} // namespace Leader
} // namespacce jj




