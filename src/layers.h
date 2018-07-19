// -*- mode: c++ -*-

/**
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keyboard.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_consumerctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_sysctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keymaps.h
  */

#pragma once

#include "config.h"

enum { QWERTY,
       FUNCTION_JJ,
#if KALEIDOSCOPE_INCLUDE_FUNCTION_ORIGINAL
       FUNCTION_ORIGINAL,
#endif
#if KALEIDOSCOPE_INCLUDE_XCODE
       XCODE,
#endif
#if KALEIDOSCOPE_INCLUDE_EMOJI
       EMOJI,
#endif
     };
