# Shifty
Arduino firmware for race shifters. Supports linear hall sensors for greater shifting accuracy than microswitches or magnetic switches.

Gear changes are semi-latched, to prevent your sim race car from popping out of gear. This is aimed to reduce driver sadness.

## Configuration
           USB
      -------------
      | TX0   RAW |    
      | RXI   GND | G
    G | GND   RST |
      | GND   VCC | Power
      |  2    A3  |
      |  3    A2  | In
   In |  4    A1  | In
      |  5    A0  | In  
   In |  6    15  |
      |  7    14  |
   In |  8    16  |
   In |  9    10  | In
      -------------

## Sensors
Any old linear hall sensor rated at 5v should do. I'm using the 49E: https://sensing.honeywell.com/index.php?ci_id=50359

Pin out
 1    2    3
VCC   G    Out

## PCB

The sensors are mounted on PCBs. The PCBs have mounting holes 4.5 cm apart.
Top row: +5v (yellow wire)
2nd row: G (white wire)
3rd row (cut in middle trace): outer sensor output (red)
4th row (cut in middle trace): inner sensor output (red)
