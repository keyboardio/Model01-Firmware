# Keyboardio Model 01 Firmware

_The default firmware for the Keyboardio Model 01_

<h3>This is a quick start guide for folks who are familiar with Arduino and prefer to use the command line. For everyone else:

 * [Check out the wiki](https://github.com/keyboardio/Kaleidoscope/wiki/Keyboardio-Model-01-Introduction) for a more in depth introduction to how the Model 01 keyboard and the Kaleidoscope firmware work. 
 
  * If you have questions, [The community forums are happy to help!](https://community.keyboard.io/)</h3>

# Download and install

## Set up the Arduino IDE

Setup the Arduino IDE on your system. Make sure you install at least version 1.8.11, since older version may not support all required features.

Out of the box, Arduino does not include support for Kaleidoscope keyboards. To be able to build and install new firmware on your keyboard, you will need to teach Arduino about Kaleidoscope.

You can find instructions for setting up the Arduino IDE and adding support for Kaleidoscope [on the Kaleidoscope wiki](https://github.com/keyboardio/Kaleidoscope/wiki/Install-Arduino)

Once that's done, you're ready to download the Model 01's firmware source code.

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

Make sure that you've picked the Model 01 from the Boards list in the tools menu.

Click the Upload button or press `Ctrl-U`.

Hold down the "Prog" key in the top left corner of your keyboard, until the compile finishes and the upload begins.


# Start to customize the firmware

You can customize your keyboard's key layout and LED effects by modifying the `Model01-Firmware.ino` file in the same directory as this README. Model01-Firmware.ino is a computer program written in 'Arduino C'. You can find documentation about Arduino C at https://arduino.cc.

You can also find Kaleidoscope-specific documentation [on our wiki](https://github.com/keyboardio/Kaleidoscope/wiki).

# Getting help

As you start to explore customization of your keyboard's firmware, the community at https://community.keyboard.io can often be a valuable resource.

# Thanks!

<3 jesse

[![Build Status](https://travis-ci.org/keyboardio/Model01-Firmware.svg?branch=master)](https://travis-ci.org/keyboardio/Model01-Firmware)
