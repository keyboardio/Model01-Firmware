# Keyboardio Model 01 Firmware

This repository contains the default firmware for Keyboardio's Model 01.

What follows is a quick start guide for folks who are familiar with Arduino and generally know what they are doing. If you want a deeper introduction, [check out the wiki.](https://github.com/keyboardio/Kaleidoscope/wiki/Keyboardio-Model-01-Introduction)

## Set up the Arduino IDE

Setup the Arduino IDE on your system. Make sure you install at least version 1.6.10, since older version may not support all required features.

### macOS

On macOS, install the Arduino IDE using [homebrew](http://brew.sh/) [cask](https://caskroom.github.io/) with `brew cask install arduino` or download the application from [the official website](https://www.arduino.cc/en/Main/Software) and move it to your `/Applications` folder.

### Linux

On Linux, your distribution's package manager probably includes the Arduino IDE, but it may be an out of date version. If your distribution installs a version of Arduino before 1.6.10, you'll need to install the Arduino IDE following the instructions [on the wiki](https://github.com/keyboardio/Kaleidoscope/wiki/Install-Arduino-support-on-Linux).

If you install Arduino into some place that's /not/ `/usr/local/arduino`, you'll need to set the `$ARDUINO_PATH` environment variable to the directory containing the `arduino` and `arduino-builder` binaries.

## Download, build and flash the firmware

First, run the following command from the command line to clone all required repositories.

```sh
make setup
```

Before you begin building and flashing the firmware, make sure your Model 01 is connected to your computer.

With your Model 01 connected to your machine, run:

```sh
make flash
```

When the builder tells you to hit Enter to continue, hold down "Prog" in the top left corner of your keyboard and hit Enter.

## Customizing the firmware

You can customize your keyboard's key layout and LED effects by modifying the `Model01-Firmware.ino` file in the `src` directory. Model01-Firmware.ino is a computer program written in 'Arduino C'. You can find documentation about Arduino C at https://arduino.cc.

To include external plugins that are not part of the official core, simply add links to their repositories to the `EXTERNAL_SOURCES` variable in the file `external_sources.txt`. Here is an example of what that might look like:

```sh
EXTERNAL_SOURCES='
https://github.com/tremby/Kaleidoscope-LEDEffect-DigitalRain.git
https://github.com/algernon/Kaleidoscope-LangPack-Hungarian.git
https://github.com/ToyKeeper/Kaleidoscope-LED-Wavepool.git
...
```

These sources will be automatically downloaded and updated when running `make setup` and `make update`.

## Updating the firmware and libraries

From time to time, you may want to update the firmware and libraries to the latest version. To do so, simply run:

```sh
make update
```

## Getting help

As you start to explore customization of your keyboard's firmware, the community at https://community.keyboard.io can often be a valuable resource.

## Thanks!

<3 jesse & Simon-Claudius

[![Build Status](https://travis-ci.org/keyboardio/Model01-Firmware.svg?branch=master)](https://travis-ci.org/keyboardio/Model01-Firmware)
