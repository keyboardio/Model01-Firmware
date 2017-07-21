#!/bin/bash
# Go to your kaleidoscope directory.

SKETCHBOOK_DIR=$HOME/Arduino

function setSketchDir {
    unameOut="$(uname -s)"
    case "${unameOut}" in
        Linux*)     machine=Linux;;
        Darwin*)    machine=Mac;;
        *)          machine="UNKNOWN:${unameOut}"
    esac

    if [[ $machine -eq "Mac" ]]; then
        SKETCHBOOK_DIR=$HOME/Documents/Arduino
        echo "OS is $machine so using SKETCHBOOK_DIR=$SKETCHBOOK_DIR"
    fi
}

function main {
    local kalDir="$1"
    setSketchDir

    if [[ "$kalDir" -eq "help" ]]; then
        echo "Usage: $0 <kaleidoscope root>"
        exit 0
    fi

    if [ -z "$kalDir" ]; then
        kalDir=$HOME/kaleidoscope
        mkdir -p $kalDir
        echo "Made dir $kalDir"
    fi

    cd $kalDir

    # Clone the hardware definitions.
    git clone --recursive https://github.com/keyboardio/Arduino-Boards.git

    # Make them available to the arduino environment
    mkdir -p $SKETCHBOOK_DIR/hardware/kaleidoscope
    ln -s $HOME/kaleidoscope/Arduino-Boards $SKETCHBOOK_DIR/hardware/kaleidoscope/avr
}

main "$@"

