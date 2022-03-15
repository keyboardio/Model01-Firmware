# Keyboardio Model 01 Firmware

This is the source code for the default firmware for the Keyboardio Model 01, as shipped from the factory. 

If you don't intend to customize your keyboard's firmware, you may want to consider using [Chrysalis](https://github.com/keyboardio/Chrysalis), our graphical configuration tool instead.

To use or customize this firmware, you need to have Arduino and Kaleidoscope installed on your computer. 

If you don't yet have Kaleidoscope and Arduino installed on your computer, [set them up now](https://kaleidoscope.readthedocs.io/en/latest/setup_toolchain.html)


## Download the Model 01 Firmware

```sh
git clone https://github.com/keyboardio/Model01-Firmware.git
```

# Build and flash the firmware

Before you begin, make sure your Model 01 is connected to your computer.

Open the sketch you wish to flash (for example, `Model01-Firmware.ino`).

Make sure that you've picked the Model 01 from the Boards list in the tools menu.

Click the Upload button or press `Ctrl-U`.

Hold down the "Prog" key in the top left corner of your keyboard, until the compile finishes and the upload begins.

# Start to customize the firmware

You can customize your keyboard's key layout and LED effects by modifying the `Model01-Firmware.ino` file in the same directory as this README. Model01-Firmware.ino is a computer program written in 'Arduino C'. You can find documentation about Arduino C at https://arduino.cc.

# Getting help

As you start to explore customization of your keyboard's firmware, the community at https://community.keyboard.io can often be a valuable resource.

# Thanks!

<3 jesse

[![Build Status](https://travis-ci.org/keyboardio/Model01-Firmware.svg?branch=master)](https://travis-ci.org/keyboardio/Model01-Firmware)
