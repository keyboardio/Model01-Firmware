# This stub makefile for a Kaleidoscope plugin pulls in 
# all targets from the Kaleidoscope-Plugin library

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
SKETCHBOOK_DIR ?= $(HOME)/Documents/Arduino
PACKAGE_DIR ?= $(HOME)/Library/Arduino15
else
SKETCHBOOK_DIR ?= $(HOME)/Arduino
PACKAGE_DIR ?= $(HOME)/.arduino15
endif


INSTALLED_ENV=$(shell ls -dt $(PACKAGE_DIR)/packages/keyboardio/hardware/avr/*|head -n 1)

ifneq ("$(wildcard $(INSTALLED_ENV)/boards.txt)","")
BOARD_HARDWARE_PATH = $(INSTALLED_ENV)
KALEIDOSCOPE_PLUGIN_MAKEFILE_DIR ?= build-tools/makefiles/
KALEIDOSCOPE_BUILDER_DIR ?= $(INSTALLED_ENV)/libraries/Kaleidoscope/bin/
endif


BOARD_HARDWARE_PATH ?= $(SKETCHBOOK_DIR)/hardware
KALEIDOSCOPE_PLUGIN_MAKEFILE_DIR ?= keyboardio/avr/build-tools/makefiles/

include $(BOARD_HARDWARE_PATH)/$(KALEIDOSCOPE_PLUGIN_MAKEFILE_DIR)/rules.mk
