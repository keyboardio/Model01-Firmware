// -*- mode: c++ -*-

#pragma once

#include "config.h"

#include <Kaleidoscope-LangPack-German.h>
#if KALEIDOSCOPE_INCLUDE_EMOJI
# include <Kaleidoscope-Emoji.h>
#endif
#if KALEIDOSCOPE_INCLUDE_TIMEKEEPER
# include <Kaleidoscope-Timekeeper.h>
#endif

namespace jj {
namespace Specials {

void configure(void);

}
}