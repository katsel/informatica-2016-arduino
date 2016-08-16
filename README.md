# Mikrocontroller am Beispiel Arduino - oder Der twitternde Farn

## Introduction
* We are using an [ESP8266](https://de.wikipedia.org/wiki/ESP8266) Microcontroller.

![WeMos D1: New and old revision](newrev-oldrev.jpg)

(Pictured on top: new revision R2 and old revision of the WeMos D1)

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

* Bonus: [example02a/example02a.ino](example02a/example02a.ino).
The LED changes brightness each 500 ms and goes off for 1 second.

## Third Example

(You need a board with a light sensor to run this, e.g. Arduino Mega ADK.
Make sure you pick the right board on `Tools -> Board: ...`)

* See [example03/example03.ino](example03/example03.ino).
 *  This program turns on the LED on the board when it's dark, and off when
    it's bright.

## Fourth example

* See [example04/example04.ino](example04/example04.ino).
* Assemble the humidity sensor.
* Disconnect the microcontroller from the computer (!).
* Connect the humidity sensor curcuit board to the microcontroller
  * VCC --> 3.3V
  * GND --> GND
  * AO (analog output) --> AO
* Connect the controller to the computer again and put the sensor into the
  flower pot.
* You can now watch the humidity values of the flower pot and other things.
