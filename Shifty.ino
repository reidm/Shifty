/*
  Shifty.ino

  Copyright (c) 2019, Reid Miller

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

//#define DEBUG 1

#include <Joystick.h>
Joystick_ Joystick =   Joystick_(0x09, JOYSTICK_TYPE_GAMEPAD, 8, 0, false, false, false,  false,  false, false, false, false, false, false, false);

#define SENSOR_COUNT 8
#define NO_BUTTON -1

const int read_threshold = 50; //Inverse of button sensitivity. Lower numbers means more sensitivity (i.e. easier to trigger buttons).
const int stale_count_threshold = 140; //Time a button will be 'held' even when the sensor is below the read_threshold
const int sensor_pin[SENSOR_COUNT] = {A3, A1, A0, A2, A9, A7, A8, A6};
const int button_map[SENSOR_COUNT] = {0, 2, 4, 10, 1, 3, 5, 7};

int sensor_minimum[SENSOR_COUNT] = {1000, 1000, 1000, 1000,
  1000, 1000, 1000, 1000};
int button_active = NO_BUTTON;
int stale_count = 0;

void setup() {
  int sensor_num;
  for(sensor_num = 0; sensor_num< SENSOR_COUNT; sensor_num++){
    pinMode(sensor_pin[sensor_num], INPUT);
    sensor_minimum[sensor_num] = analogRead(sensor_pin[sensor_num]);
  }
  Joystick.begin();
  #ifdef DEBUG
  Serial.begin(9600);
  #endif
}

void loop() {
  int sensor_num;
  int value = 0;
  int flag = 0;
  for(sensor_num = 0; sensor_num < SENSOR_COUNT; sensor_num++){
      value = analogRead(sensor_pin[sensor_num]);
      if(value < sensor_minimum[sensor_num])
        sensor_minimum[sensor_num] = value;
      value -= sensor_minimum[sensor_num];

      if(value > read_threshold){
        flag = 1;
        stale_count = 0;
        if(button_active != NO_BUTTON && button_active != sensor_num){
          Joystick.setButton(button_map[button_active], LOW);
        }
        Joystick.setButton(button_map[sensor_num], HIGH);
        button_active = sensor_num;
      }

      #ifdef DEBUG
      Serial.print(value);
      if (sensor_num < SENSOR_COUNT-1){
        Serial.print(" / ");
      } else{
        Serial.println("");
        delay(30);
      }
      #endif
  }

  if(!flag)
    stale_count +=1;

  if(stale_count >= stale_count_threshold){
    Joystick.setButton(button_map[button_active], LOW);
    stale_count = 0;
  }


}
