#include "Kaleidoscope-NumPad.h"
#include "LEDUtils.h"
#include "Kaleidoscope.h"
#include "layers.h"

byte NumPad_::row = 255, NumPad_::col = 255;
uint8_t NumPad_::numPadLayer;
bool NumPad_::cleanupDone = true;
cRGB NumPad_::numpad_color;

void NumPad_::begin(void) {
  Kaleidoscope.useLoopHook(loopHook);
}

void NumPad_::loopHook(bool postClear) {
  if (!postClear)
    return;

  if (!Layer.isOn(numPadLayer)) {
    if (!cleanupDone) {
      LEDControl.set_mode(LEDControl.get_mode_index());
      cleanupDone = true;
    }
    return;
  }

  cleanupDone = false;
  bool numState = !!(kaleidoscope::hid::getKeyboardLEDs() & LED_NUM_LOCK);
  if (!numState) {
    kaleidoscope::hid::pressKey(Key_KeypadNumLock);
  }

  LEDControl.set_mode(LEDControl.get_mode_index());

  for (uint8_t r = 0; r < ROWS; r++) {
    for (uint8_t c = 0; c < COLS; c++) {
      Key k = Layer.lookupOnActiveLayer(r, c);
      Key layer_key = Layer.getKey(numPadLayer, r, c);

      if (k == LockLayer(numPadLayer)) {
        row  = r;
        col = c;
      }

      if ((k != layer_key) || (k.flags != KEY_FLAGS)) {
        LEDControl.refreshAt(r, c);
      } else {
        LEDControl.setCrgbAt(r, c, numpad_color);
      }
    }
  }

  if (row > ROWS || col > COLS)
    return;
}

  cRGB color = breath_compute();


  NumPad_ NumPad;



byte FuncPad_::row = 255, FuncPad_::col = 255;
uint8_t FuncPad_::FuncPadLayer;
bool FuncPad_::cleanupDone = true;
cRGB FuncPad_::Funcpad_color;

void FuncPad_::begin(void) {
  Kaleidoscope.useLoopHook(loopHook);
}

void FuncPad_::loopHook(bool postClear) {
  if (!postClear)
    return;

  if (!Layer.isOn(FuncPadLayer)) {
    if (!cleanupDone) {
      LEDControl.set_mode(LEDControl.get_mode_index());
      cleanupDone = true;
    }
    return;
  }

  cleanupDone = false;
  bool FuncState = !!(kaleidoscope::hid::getKeyboardLEDs() & LED_NUM_LOCK);
  if (!FuncState) {
    kaleidoscope::hid::pressKey(Key_KeypadNumLock);
  }

  LEDControl.set_mode(LEDControl.get_mode_index());

  for (uint8_t r = 0; r < ROWS; r++) {
    for (uint8_t c = 0; c < COLS; c++) {
      Key k = Layer.lookupOnActiveLayer(r, c);
      Key layer_key = Layer.getKey(FuncPadLayer, r, c);

      if (k == LockLayer(FuncPadLayer)) {
        row  = r;
        col = c;
      }

      if ((k != layer_key) || (k.flags != KEY_FLAGS)) {
        LEDControl.refreshAt(r, c);
      } else {
        LEDControl.setCrgbAt(r, c, FuncPad_::Funcpad_color);
      }
    }
  }

  if (row > ROWS || col > COLS)
    return;


  LEDControl.setCrgbAt(row, col, color);
}

FuncPad_ FuncPad;


byte QwertyPad_::row = 255, QwertyPad_::col = 255;
uint8_t QwertyPad_::QwertyPadLayer;
bool QwertyPad_::cleanupDone = true;
cRGB QwertyPad_::Qwertypad_color;

void QwertyPad_::begin(void) {
  Kaleidoscope.useLoopHook(loopHook);
}

void QwertyPad_::loopHook(bool postClear) {
  if (!postClear)
    return;

  if (!Layer.isOn(QwertyPadLayer)) {
    if (!cleanupDone) {
      LEDControl.set_mode(LEDControl.get_mode_index());
      cleanupDone = true;
    }
    return;
  }

  cleanupDone = false;
  bool QwertyState = !!(kaleidoscope::hid::getKeyboardLEDs() & LED_NUM_LOCK);
  if (!QwertyState) {
    kaleidoscope::hid::pressKey(Key_KeypadNumLock);
  }

  LEDControl.set_mode(LEDControl.get_mode_index());

  for (uint8_t r = 0; r < ROWS; r++) {
    for (uint8_t c = 0; c < COLS; c++) {
      Key k = Layer.lookupOnActiveLayer(r, c);
      Key layer_key = Layer.getKey(QwertyPadLayer, r, c);

      if (k == LockLayer(QwertyPadLayer)) {
        row  = r;
        col = c;
      }

      if ((k != layer_key) || (k.flags != KEY_FLAGS)) {
        LEDControl.refreshAt(r, c);
      } else {
        LEDControl.setCrgbAt(r, c, QwertyPad_::Qwertypad_color);
      }
    }
  }

  if (row > ROWS || col > COLS)
    return;


  LEDControl.setCrgbAt(row, col, color);
}

QwertyPad_ QwertyPad;


byte GamingPad_::row = 255, GamingPad_::col = 255;
uint8_t GamingPad_::GamingPadLayer;
bool GamingPad_::cleanupDone = true;
cRGB GamingPad_::Gamingpad_color;

void GamingPad_::begin(void) {
  Kaleidoscope.useLoopHook(loopHook);
}

void GamingPad_::loopHook(bool postClear) {
  if (!postClear)
    return;

  if (!Layer.isOn(GamingPadLayer)) {
    if (!cleanupDone) {
      LEDControl.set_mode(LEDControl.get_mode_index());
      cleanupDone = true;
    }
    return;
  }

  cleanupDone = false;
  bool GamingState = !!(kaleidoscope::hid::getKeyboardLEDs() & LED_NUM_LOCK);
  if (!GamingState) {
    kaleidoscope::hid::pressKey(Key_KeypadNumLock);
  }

  LEDControl.set_mode(LEDControl.get_mode_index());

  for (uint8_t r = 0; r < ROWS; r++) {
    for (uint8_t c = 0; c < COLS; c++) {
      Key k = Layer.lookupOnActiveLayer(r, c);
      Key layer_key = Layer.getKey(GamingPadLayer, r, c);

      if (k == LockLayer(GamingPadLayer)) {
        row  = r;
        col = c;
      }

      if ((k != layer_key) || (k.flags != KEY_FLAGS)) {
        LEDControl.refreshAt(r, c);
      } else {
        LEDControl.setCrgbAt(r, c, GamingPad_::Gamingpad_color);
      }
    }
  }

  if (row > ROWS || col > COLS)
    return;


  LEDControl.setCrgbAt(row, col, color);
}

GamingPad_ GamingPad;
