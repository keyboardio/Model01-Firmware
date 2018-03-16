#pragma once

#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-Macros.h"
#include "LEDUtils.h"

class NumPad_ : public KaleidoscopePlugin {
 public:
  NumPad_(void) {}

  void begin(void) final;

  static uint8_t numPadLayer;
  static cRGB numpad_color;

 private:
  static void loopHook(const bool postClear);

  static byte row, col;
  static bool cleanupDone;
};

class FuncPad_ : public KaleidoscopePlugin {
 public:
  FuncPad_(void) {}

  void begin(void) final;

  static uint8_t FuncPadLayer;
  static cRGB Funcpad_color;

 private:
  static void loopHook(const bool postClear);

  static byte row, col;
  static bool cleanupDone;
};

class QwertyPad_ : public KaleidoscopePlugin {
 public:
  QwertyPad_(void) {}

  void begin(void) final;

  static uint8_t QwertyPadLayer;
  static cRGB Qwertypad_color;

 private:
  static void loopHook(const bool postClear);

  static byte row, col;
  static bool cleanupDone;
};

class GamingPad_ : public KaleidoscopePlugin {
 public:
  GamingPad_(void) {}

  void begin(void) final;

  static uint8_t GamingPadLayer;
  static cRGB Gamingpad_color;

 private:
  static void loopHook(const bool postClear);

  static byte row, col;
  static bool cleanupDone;
};

extern NumPad_ NumPad;
extern FuncPad_ FuncPad;
extern QwertyPad_ QwertyPad;
extern GamingPad_ GamingPad;
