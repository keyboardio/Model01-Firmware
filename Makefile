# This stub makefile for a Kaleidoscope plugin pulls in
# all targets from the Kaleidoscope-Plugin library

MAKEFILE_PREFIX=keyboardio/avr/libraries/Kaleidoscope-Plugin/build
UNAME_S := $(shell uname -s)

ifneq ($(SKETCHBOOK_DIR),)
BOARD_HARDWARE_PATH ?= $(SKETCHBOOK_DIR)/hardware
else
ifeq ($(UNAME_S),Darwin)
BOARD_HARDWARE_PATH ?= $(HOME)/Documents/Arduino/hardware
else
BOARD_HARDWARE_PATH ?= $(HOME)/Arduino/hardware
endif
endif

include $(BOARD_HARDWARE_PATH)/$(MAKEFILE_PREFIX)/rules.mk
