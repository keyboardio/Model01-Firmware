#!/usr/bin/env bash

set -o errexit
set -o pipefail
set -u

_info() {
  >&2 echo "[info] $*"
}

_sdk_is_installed() {
  which arduino-builder > /dev/null 2>&1
}

_main() {
  local arduino_dir="$HOME/Arduino"
  if [[ "$(uname)" == "Darwin" ]]; then
    arduino_dir="$HOME/Documents/Arduino"
    _sdk_is_installed \
      || brew cask reinstall arduino \
      || _info 'Failed to install the Arduino SDK with brew cask. Please install it manually.'
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
