# Kaleidoscope

Flexible firmware for Arduino-powered keyboards

# Getting Started

Pick a directory to work in, you'll need to clone multiple repositories. We'll assume you picked `$HOME/kaleidoscope`, if you chose another adapt the commands below accordingly.

## Setup the Arduino IDE

Setup the Arduino IDE on your system. Make sure you install at least version 1.6, since older version may not support all required features.

* On Linux, follow the instructions [on the wiki](https://github.com/keyboardio/Kaleidoscope/wiki/Arduino-Setup-Linux), installing the Arduino package somewhere that 'arduino' and 'arduino-builder' end up in your $PATH
* On macOS, install using [homebrew](http://brew.sh/) [cask](https://caskroom.github.io/) with `brew cask install arduino` or download the application from [the official website](https://www.arduino.cc/en/Main/Software) and move it to your `/Applications` folder.

## Install the Kaleidoscope Hardware Definitions

```sh
# You'll need to know your arduino sketchbook directory

# on macOS the default is
SKETCHBOOK_DIR=$HOME/Documents/Arduino
# on Linux the default is
SKETCHBOOK_DIR=$HOME/Arduino

# Make a directory for the Arduino sketchbook and our hardware definitions
mkdir -p $SKETCHBOOK_DIR/hardware/keyboardio

# then clone the hardware definitions to make them available to the arduino environment
git clone --recursive https://github.com/keyboardio/Arduino-Boards.git $SKETCHBOOK_DIR/hardware/keyboardio/avr
```

## Clone and Build the Kaleidoscope Firmware for the Model 01

```sh
# go to your Arduino sketchbook
cd $SKETCHBOOK

# then clone the firmware repository
git clone https://github.com/keyboardio/Model01-Firmware.git

# and build your firmware!
cd Model01-Firmware

make flash

# When the builder tells you to hit return to continue,
# hold down "prog" on your keyboard and hit return.
```

<3 jesse

[![Build Status](https://travis-ci.org/keyboardio/Model01-Firmware.svg?branch=master)](https://travis-ci.org/keyboardio/Model01-Firmware)
