# This stub makefile for a Kaleidoscope plugin pulls in 
# all targets from the Kaleidoscope-Plugin library

MAKEFILE_PREFIX=keyboardio/avr/libraries/Kaleidoscope-Plugin/build
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
SKETCHBOOK_DIR ?= $(HOME)/Documents/Arduino/
else
SKETCHBOOK_DIR ?= $(HOME)/arduino
endif

BOARD_HARDWARE_PATH ?= $(SKETCHBOOK_DIR)/hardware
include $(BOARD_HARDWARE_PATH)/$(MAKEFILE_PREFIX)/rules.mk
