# Kaleidoscope

Flexible firmware for Arduino-powered keyboards


# Set up the Arduino IDE

Setup the Arduino IDE on your system. Make sure you install at least version 1.6, since older version may not support all required features.

# macOS

On macOS, install the Arduino IDE using [homebrew](http://brew.sh/) [cask](https://caskroom.github.io/) with `brew cask install arduino` or download the application from [the official website](https://www.arduino.cc/en/Main/Software) and move it to your `/Applications` folder.

## Linux

On Linux, your distribution's package manager probably includes the Arduino IDE, but it may be an out of date version. If your distribution installs a version of Arduino before 1.6.3 or so, you'll need to install the Arduino IDE following the instructions [on the wiki](https://github.com/keyboardio/Kaleidoscope/wiki/Arduino-Setup-Linux), installing the Arduino package somewhere that 'arduino' and 'arduino-builder' end up in your $PATH

# Create and navigate to the Arduino Sketchbook directory

## MacOS
```sh
mkdir -p $HOME/Documents/Arduino
cd $HOME/Documents/Arduino 
```

## Linux

```sh
mkdir -p $HOME/Arduino
cd $HOME/Arduino 
```

# Download hardware platform, library source code and firmware source code

```sh
mkdir -p hardware/keyboardio

# then clone the hardware definitions to make them available to the arduino environment
git clone --recursive https://github.com/keyboardio/Arduino-Boards.git hardware/keyboardio/avr

# then clone the firmware repository
git clone https://github.com/keyboardio/Model01-Firmware.git
````


# Build and flash the firmware from the commandline!

```sh
cd Model01-Firmware
make flash
```

When the builder tells you to hit Enter to continue, hold down "Prog" on your keyboard and hit Enter.

<3 jesse

[![Build Status](https://travis-ci.org/keyboardio/Model01-Firmware.svg?branch=master)](https://travis-ci.org/keyboardio/Model01-Firmware)
