# Model01-Firmware

This is the standard firmware for the Model01.

# Getting Started

Pick a directory to work in, you'll need to clone multiple repositories. We'll assume you picked `$HOME/kaleidoscope`, if you chose another adapt the commands below accordingly.

## Dependencies

### CLI Tools
Install wget `brew install wget` if on mac, linux users, you know what to do.

### Setup the Arduino IDE

Setup the Arduino IDE on your system. Make sure you install at least version 1.6, since older version may not support all required features.

* On Linux, follow the instructions [on the wiki](https://github.com/keyboardio/Kaleidoscope/wiki/Arduino-Setup-Linux).
* On macOS, install using [homebrew](http://brew.sh/) [cask](https://caskroom.github.io/) with `brew cask install arduino` or download the application from [the official website](https://www.arduino.cc/en/Main/Software) and move it to your `/Applications` folder.

### Install the Kaleidoscope Hardware Definitions

Run `./init.sh`, if you have selected a dir other than $HOME/kaleidoscope pass it as the first argument.

### Make the project

```sh
make
```

## Editing the keymap and uploading.

```sh
open -a Arduino Model01-Firmware.ino
```

Before the upload process begins you must press and hold the prod button on the keyboard, this is a security measure and
does not need to be done while the project is compiling.
Make your changes and when you're ready go ahead and upload (`CMD-U` on Mac).

<3 jesse

[![Build
Status](https://travis-ci.org/keyboardio/Kaleidoscope.svg?branch=master)](https://travis-ci.org/keyboardio/Kaleidoscope)
