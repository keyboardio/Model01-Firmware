## Platform-specific overrides
# Shamelessly stolen from git's Makefile
uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')

ARDUINO_HARDWARE_PATH=${HOME}/Arduino/hardware

ifeq ($(uname_S),Darwin)
	ARDUINO_HARDWARE_PATH=${HOME}/Documents/Arduino/hardware
endif

BUILDER_PATH=${ARDUINO_HARDWARE_PATH}/keyboardio/avr/libraries/Kaleidoscope/tools/kaleidoscope-builder


# default action for `make` is `build`
build:

astyle:
		find . -type f -name \*.cpp |xargs -n 1 astyle --style=google
		find . -type f -name \*.ino |xargs -n 1 astyle --style=google
		find . -type f -name \*.h |xargs -n 1 astyle --style=google

%:
	${BUILDER_PATH} $@
