# ipv4_16x2
Small program for displaying IPv4 address on hd44780 LCD display

by addei

![LCD screen with IPv4 address](ipv4_16x2.jpg)

### Requirements
+ WiringPi
+ make
+ gcc
+ cron

Small knowledge how to wire Raspberry Pi.

### Components
+ Raspberry Pi (2..4)
+ Hitachi hd44780 LCD panel (or clone)
+ 220 Ohm resistor
+ 10k Ohm Potentiometer
+ atleast 11 wires
+ Breadboard

### Wiring
Program uses 4-bit mode to display text on the screen. 
+ lcd_rs  -> physical pin 37
+ lcd_en  -> physical pin 35
+ lcd_db4 -> physical pin 33
+ lcd_db5 -> physical pin 31
+ lcd_db6 -> physical pin 29
+ lcd_db7 -> physical pin 40

Screen indicators for the Pins may vary.

### Installation
The program can be easily installed by running the installation script.

    $ chmod -x install.sh
    $ ./install.sh

Installation script automatically adds cronjob for the program!
Program needs sudo at one point. Script installs program into `/opt/bin/ipv4_16x2` folder.

### Build
User can also build software by simply executing the make command.

    $ make

### Note!
If the Pi network card has a different name than the default or Pi uses Wi-Fi, the user should make changes to the line of 26 in `source/main.c` and rebuild.

