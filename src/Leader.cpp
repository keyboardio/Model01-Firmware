// -*- mode: c++ -*-

#include "config.h"
#include "keydefs.h"

#include "Leader.h"
#include <Kaleidoscope-Leader.h>
#include <Kaleidoscope-Macros.h>

namespace jj {
namespace Leader {
namespace {

}
}
}


namespace jj {
namespace Leader {

static void launchXcode(uint8_t seq_index) {
  ::Macros.play(MACRO(Tr(LGUI(Key_F13))));
}
static void launchMusic(uint8_t seq_index) {
  ::Macros.play(MACRO(Tr(LGUI(Key_F14))));
}
static void launchBrowser(uint8_t seq_index) {
  ::Macros.play(MACRO(Tr(LGUI(Key_F15))));
}
static void launchTerminal(uint8_t seq_index) {
  ::Macros.play(MACRO(Tr(LGUI(Key_F16))));
}
static void launchChat(uint8_t seq_index) {
  ::Macros.play(MACRO(Tr(LGUI(Key_F17))));
}
static void launchDiff(uint8_t seq_index) {
  ::Macros.play(MACRO(Tr(LGUI(Key_F18))));
}
static void compose(uint8_t seq_index) {
  ::Macros.play(MACRO(Tr(Key_NonUsBackslashAndPipe)));
}
static void emoji(uint8_t seq_index) {
  ::Macros.play(MACRO(Tr(LALT(LSHIFT(Key_M)))));
}
static void printCurrentDate(uint8_t seq_index) {
  ::Macros.play(MACRO(Tr(LGUI(LALT(LSHIFT(Key_D))))));
}

static const kaleidoscope::Leader::dictionary_t leader_dictionary[] PROGMEM = LEADER_DICT(
{LEADER_SEQ(LEAD(MAIN), Key_C), compose},
{LEADER_SEQ(LEAD(MAIN), Key_E), emoji},
{LEADER_SEQ(LEAD(MAIN), Key_D), printCurrentDate},
{LEADER_SEQ(LEAD(MAIN), Key_O, Key_B), launchBrowser},
{LEADER_SEQ(LEAD(MAIN), Key_O, Key_C), launchChat},
{LEADER_SEQ(LEAD(MAIN), Key_O, Key_M), launchMusic},
{LEADER_SEQ(LEAD(MAIN), Key_O, Key_D), launchDiff},
{LEADER_SEQ(LEAD(MAIN), Key_O, Key_T), launchTerminal},
{LEADER_SEQ(LEAD(MAIN), Key_O, Key_X), launchXcode});

void configure(void) {
  ::Leader.dictionary = leader_dictionary;
}



namespace {


} // namespace
} // namespace Leader
} // namespacce jj




