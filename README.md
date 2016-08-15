# Mikrocontroller am Beispiel Arduino - oder Der twitternde Farn

## Introduction
* We are using an [ESP8266](https://de.wikipedia.org/wiki/ESP8266) Microcontroller

## Installation

* Download Arduino IDE from https://www.arduino.cc/en/main/software
* Unpack and run
* Make the Arduino IDE familiar with your microcontroller:
  * Go to `File -> Preferences` and add the URL http://arduino.esp8266.com/stable/package_esp8266com_index.json under "Additional Board Manager URLs"
  * open `Tools -> Board: ... -> Board Manager`
  * search for "ESP8266" and select the matching driver below
  * click `install`
  * open `Tools -> Board: ...` and select "WeMos D1(Retired)" or "WeMos D1 R2 & mini" according to the name printed on your board
* USB setup:
  * Connect your Arduino board to the USB port of your computer and choose `Tools -> Port -> /dev/ttyUSB0`.
  * On Linux: `sudo chmod o+rw /dev/ttyUSB0` to enable read/write to that port as a normal user.
  You have to do this each time you disconnect and reconnect the microcontroller.

## First example

The IDE shows two functions.
`setup()` is run once at the beginning (used for assigning start values to variables etc.).
`loop()` is run repeatedly.

* See [example01/example01.ino](example01/example01.ino).
* Click on the small check mark ("verify") on top to compile the code.
When it's done (and there are no errors) it will show "Done compiling."
* Upload the compiled code to the board using the arrow button (2nd from left).
If it works, you should see

        Uploading 227200 bytes from /tmp/build097a90998118e101b31481be08ada238.tmp/example01.ino.bin to flash at 0x00000000
        ................................................................................ [ 36% ]
        ................................................................................ [ 72% ]
        ..............................................................                   [ 100% ]

The LED labelled `SCK` goes off.

You can now control the brightness of your LED with the `MEIN_LED` value.

## Second example

* See [example02/example02.ino](example02/example02.ino).
* Verify and upload the code.
* The LED will blink.
