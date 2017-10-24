ABG/Celtic firmware variant layout
==================================

This repository contains a small number of commits that vary the default 
keyboardio firmware to make multilingual typing more intuitive.

The commits should be mostly atomic, however the base layer changes require
that three keys be moved from the base layer to the Fn layer, so failing to
apply the Fn layer commits will result in loss of functionality.

How to use
----------

Follow the instructions in the README.md file, but instead of cloning
`keyboardio/Model01-Firmware`, clone `andrewgdotcom/Model01-Firmware`.
Otherwise the steps are identical.

Andrew.
