# Keyboardio Model 01 Firmware

The default firmware for the Keyboardio Model 01


# Download and install

## Set up the Arduino IDE

Setup the Arduino IDE on your system. Make sure you install at least version 1.6, since older version may not support all required features.

### macOS

On macOS, install the Arduino IDE using [homebrew](http://brew.sh/) [cask](https://caskroom.github.io/) with `brew cask install arduino` or download the application from [the official website](https://www.arduino.cc/en/Main/Software) and move it to your `/Applications` folder.


### Linux

On Linux, your distribution's package manager probably includes the Arduino IDE, but it may be an out of date version. If your distribution installs a version of Arduino before 1.6.3 or so, you'll need to install the Arduino IDE following the instructions [on the wiki](https://github.com/keyboardio/Kaleidoscope/wiki/Arduino-Setup-Linux).

If you install Arduino into some place that's /not/ `/usr/local/arduino`, you'll need to set the `$ARDUINO_PATH` environment variable to the directory containing the `arduino` and `arduino-builder` binaries.

## Create and navigate to the Arduino Sketchbook directory

### MacOS
```sh
mkdir -p $HOME/Documents/Arduino
cd $HOME/Documents/Arduino 
```

### Linux

```sh
mkdir -p $HOME/Arduino
cd $HOME/Arduino 
```

## Download hardware platform, including library source code 

```sh
mkdir -p hardware/keyboardio

## then clone the hardware definitions to make them available to the arduino environment
git clone --recursive https://github.com/keyboardio/Arduino-Boards.git hardware/keyboardio/avr
````


## Download the Model 01 Firmware

```sh
git clone https://github.com/keyboardio/Model01-Firmware.git
```

# Build and flash the firmware

Before you begin, make sure your Model 01 is connected to your computer.

### Option 1: From the command line

```sh
cd Model01-Firmware
make flash
```

When the builder tells you to hit Enter to continue, hold down "Prog" in the top left corner of your keyboard and hit Enter.

### Option 2: From the Arduino IDE


Open the sketch you wish to flash (for example, `Model01-Firmware.ino`).

Click the Upload button or press `Ctrl-U`.

Hold down the "Prog" key in the top left corner of your keyboard, until the compile finishes and the upload begins.

# Thanks!

<3 jesse

[![Build Status](https://travis-ci.org/keyboardio/Model01-Firmware.svg?branch=master)](https://travis-ci.org/keyboardio/Model01-Firmware)
