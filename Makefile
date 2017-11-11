BOARD_HARDWARE_PATH ?= hardware
KALEIDOSCOPE_PLUGIN_MAKEFILE_DIR ?= keyboardio/avr/build-tools/makefiles/

setup:
	./.scripts.sh --setup

update:
	./.scripts.sh --update

include $(wildcard $(BOARD_HARDWARE_PATH)/$(KALEIDOSCOPE_PLUGIN_MAKEFILE_DIR)/rules.mk)