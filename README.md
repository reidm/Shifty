# Shifty: The Ultimate Shifter Firmware!
Arduino firmware for race shifters. Supports 8 linear hall sensors, these allow for greater shifting accuracy than microswitch or magnetic switch alternatives.

Gear changes are semi-latched, to prevent your sim race car from popping out of gear. This is aimed to reduce mid-race driver sadness.

Shifty is licensed under GPL v3.

## Configuration
This firmware was prepared for the Arduino Pro Micro, but should function on any Arduino hardware that supports the Joystick library. Uno's only have 6 analog readable pins, since we want to use 8 analog channels, they aren't a great alternative.


```
           USB
      -------------
      | TX0   RAW |    
      | RXI   GND | G
    G | GND   RST |
      | GND   VCC | VCC
      |  2    A3  | In
      |  3    A2  | In
   In |  4    A1  | In
      |  5    A0  | In  
   In |  6    15  |
      |  7    14  |
   In |  8    16  |
   In |  9    10  | 
      -------------
```

## Sensors
Any old linear hall effect sensor rated at 5v should do. I'm using the [49E sensor](https://sensing.honeywell.com/index.php?ci_id=50359). Here is a no nonsense introduction to [wiring up the 49e with an Arduino](https://knitsbits.wordpress.com/2015/04/26/49e-sensor-and-arduino/), care of zlickovski.

#### Sensor Pin Out (Text Facing Forwards)
```
 1    2    3
VCC   G    Out
```

## PCB

The sensors are mounted on PCBs. The PCBs have mounting holes 4.5 cm apart. See attached pictures for some visual reference.

Top row: +5v (yellow wire)
2nd row: G (white wire)
3rd row (cut in middle trace): outer sensor output (red)
4th row (cut in middle trace): inner sensor output (red)

## Installation

Follow instructions to install ArduinoJoystickLibrary into Arduino IDE: https://github.com/MHeironimus/ArduinoJoystickLibrary

Use the Arduino IDE to compile and load Shifty.ino on to your board. The device will now function as a plug-n-play USB joystick device.

### Device Name

The USB device name can be changed by modifying Arduino IDE's boards.txt file. I suggest the following values:

```
micro.build.vid=0x9991
micro.build.pid=0x9992
micro.build.usb_product="Shifty"
```
