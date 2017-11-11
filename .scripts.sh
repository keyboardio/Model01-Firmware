#!/usr/bin/env sh

source external_sources.txt

update () {

    # Updates libraries

    __gitupdate () {
        (cd $1
         git checkout -q master
         git pull -q -ff
         git submodule --quiet update --init --recursive
         git submodule --quiet foreach --recursive 'echo "Updating $path..."; git checkout -q master; git pull -q -ff')
    }

    for i in $EXTERNAL_SOURCES
    do
    f=lib/`basename ${i%.*}`
        echo "Updating $f"
        __gitupdate $f
    done

    echo "Updating hardware/keyboardio/avr"
    __gitupdate hardware/keyboardio/avr
}

setup () {

# Delete existing directories (e.g. in case `make setup` is run a second time)

    if [ -d "lib" ]
    then
        rm -rf lib
    fi

    if [ -d "hardware" ]
    then
        rm -rf hardware
    fi

# Create required directories
    mkdir lib
    mkdir hardware

# Clone external sources
    for i in $EXTERNAL_SOURCES
    do
        echo "Cloning $i"
        git clone -q $i lib/`basename ${i%.*}`
    done

# Clone Arduino boards for Kaleidoscope
    echo "Cloning https://github.com/keyboardio/Arduino-Boards.git"
    git clone -q https://github.com/keyboardio/Arduino-Boards.git hardware/keyboardio/avr

# Update repositories
    update
}

# Parse options
case $1 in
    --setup)
    setup
    ;;

    --update)
    update
    ;;

    *)
    echo "No option provided. Aborting."
    exit 1
    ;;

esac
