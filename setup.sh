#!/usr/bin/env bash

set -o errexit
set -o pipefail
set -u

ARDUINO_VERSION="${ARDUINO_VERSION:-1.8.5}"

_info() {
  >&2 echo "[info] $*"
}

_sdk_is_installed() {
  which arduino-builder > /dev/null 2>&1
}

_sdk_linux_setup() {
  local archive="arduino-${ARDUINO_VERSION}-linux64.tar.xz"
  pushd "$(mktemp -d)"
  wget "https://downloads.arduino.cc/${archive}"
  tar xvf "${archive}"
  _info 'Copying the arduino requires sudo privilege. Please enter your password.'

  sudo mv "arduino-${ARDUINO_VERSION}" '/usr/local/arduino'
  pushd '/usr/local/arduino'
  sudo ./install.sh
  popd

  if [[ "$(lsb_release  --id --short)" == 'Ubuntu' ]]; then
    wget 'https://raw.githubusercontent.com/keyboardio/Kaleidoscope/master/etc/99-kaleidoscope.rules'
    sudo cp '99-kaleidoscope.rules' '/etc/udev/rules.d'
    _info 'Then disconnect and reconnect the keyboard for that change to take effect.'
  fi

  if [[ "$(groups | grep dialout || echo $?)" == '1' ]]; then
    sudo adduser "$USER" dialout
    newgrp dialout
    _info 'You may have to invoke "su - $USER", or log out and in again.'
  fi

  _info 'Please add "export ARDUINO_PATH=/usr/local/arduino" to your shell profile (e.g. .bashrc, .zshrc, etc.)'

  _info 'In case of issues, refer to the manual instructions.'
  _info 'https://github.com/keyboardio/Kaleidoscope/wiki/Install-Arduino-support-on-Linux'
  popd
}

_main() {
  local arduino_dir="$HOME/Arduino"
  if [[ "$(uname)" == "Darwin" ]]; then
    arduino_dir="$HOME/Documents/Arduino"
    _sdk_is_installed \
      || brew cask reinstall arduino \
      || _info 'Failed to install the Arduino SDK with brew cask. Please install it manually.'
  elif [[ "$(uname)" == "Linux" ]]; then
    _sdk_is_installed \
      || _sdk_linux_setup
  fi
  local keyboardio_dir="${arduino_dir}/hardware/keyboardio"
  if [[ -d "${keyboardio_dir}" ]]; then
    _info 'It seems like the hardware platfrom and source code is already install.'
    _info "To force the reinstallation, remove the '${keyboardio_dir}' directory and re-run '$0'."
  else
    mkdir -p "${keyboardio_dir}"
    _info 'Downloading hardware platform and source code ...'
    git clone --recursive https://github.com/keyboardio/Arduino-Boards.git "${keyboardio_dir}/avr"
  fi

  _sdk_is_installed || {
    _info 'You mush install the Arduino SDK to continue. See "README.md".'
    exit 1
  }

  _info 'Done! You should be able to run "make flash" with the content of the .ino file in this repository.'
}

_main "$@"
