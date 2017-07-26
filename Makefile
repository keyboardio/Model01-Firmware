# This stub makefile for a Kaleidoscope plugin pulls in
# all targets from the Kaleidoscope-Plugin library

MAKEFILE_PREFIX=kaleidoscope/avr/libraries/Kaleidoscope-Plugin/build
UNAME_S := $(shell uname -s)

# Linux
SKETCHBOOK_DIR=$(HOME)/Arduino

# MacOS
ifeq ($(UNAME_S),Darwin)
	 SKETCHBOOK_DIR=$(HOME)/Documents/Arduino
endif

BOARD_HARDWARE_PATH = $(SKETCHBOOK_DIR)/hardware

include $(BOARD_HARDWARE_PATH)/$(MAKEFILE_PREFIX)/*.mk
