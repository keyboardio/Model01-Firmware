// -*- mode: c++ -*-

#pragma once

#include <Kaleidoscope-LEDEffect-SolidColor.h>

namespace jj {
namespace LEDControl {

static kaleidoscope::plugin::LEDSolidColor solidRed(160, 0, 0);
static kaleidoscope::plugin::LEDSolidColor solidOrange(140, 70, 0);
static kaleidoscope::plugin::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::plugin::LEDSolidColor solidGreen(0, 160, 0);
static kaleidoscope::plugin::LEDSolidColor solidBlue(0, 70, 130);
static kaleidoscope::plugin::LEDSolidColor solidIndigo(0, 0, 170);
static kaleidoscope::plugin::LEDSolidColor solidViolet(130, 0, 120);
static kaleidoscope::plugin::LEDSolidColor solidPaleWhite(70, 70, 70);
static kaleidoscope::plugin::LEDSolidColor solidPaleRed(70, 0, 0);
static kaleidoscope::plugin::LEDSolidColor solidBrightRed(200, 0, 0);

void configure(void);
void pauseLEDs(void);
void unpauseLEDs(void);

}
}
