# Very Simple Power Menu

Very simple power menu with: shutdown, reboot, logout and sleep buttons. Press Esc to exit.

## Technologies

This project was created with:

* Qt version: >4

## Setup

```
$ mkdir -p build
$ cd build
$ qmake ../src/vspowermenu.pro
$ make
$ make install
```

## Configuration

Buttons can be configured in ``` ~/.config/vspmsettings.conf ```.

Example configuration:

```
[General]
shutdownCommand=shutdown now
rebootCommand=reboot
sleepCommand=systemctl suspend
logoutCommand=hyprctl dispatch exit
```
