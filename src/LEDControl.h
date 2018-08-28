// -*- mode: c++ -*-

#pragma once

#include <Kaleidoscope-LEDEffect-SolidColor.h>

namespace jj {
namespace LEDControl {

static kaleidoscope::LEDSolidColor solidRed(160, 0, 0);
static kaleidoscope::LEDSolidColor solidOrange(140, 70, 0);
static kaleidoscope::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::LEDSolidColor solidGreen(0, 160, 0);
static kaleidoscope::LEDSolidColor solidBlue(0, 70, 130);
static kaleidoscope::LEDSolidColor solidIndigo(0, 0, 170);
static kaleidoscope::LEDSolidColor solidViolet(130, 0, 120);
static kaleidoscope::LEDSolidColor solidPaleWhite(70, 70, 70);
static kaleidoscope::LEDSolidColor solidPaleRed(70, 0, 0);
static kaleidoscope::LEDSolidColor solidBrightRed(200, 0, 0);

void configure(void);
void pauseLEDs(void);
void unpauseLEDs(void);

}
}
