/*
 * Author: John Stillwell
 * 
 
MIT License

Copyright (c) 2017 John Stillwell

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "Fan.h"

char werd;
String command;

const int FAN_STOP = 0;
const int FAN_START=100;
const int FAN_MAX = 255;

int _fan1 = 3;
int _fan2 = 4;
int _fan3 = 5;
int _fan4 = 6;

Fan fan1(_fan1);
Fan fan2(_fan2);
Fan fan3(_fan3);
Fan fan4(_fan4);

void setup() {
  // put your setup code here, to run once:
  fan1.begin(FAN_START);
  fan2.begin(FAN_START);
  fan3.begin(FAN_START);
  fan4.begin(FAN_START);

  Serial.begin(115200);
}

void loop() {
  while ( Serial.available() > 0 ) {
    // small delay because it can only deliver the bytes so quickly
    delay(5);
    // you have to read one byte (one character) at a time
    werd = Serial.read();
    // append the character to our "command" string
    command += werd;
  }

  Serial.flush();
  if(command.length() > 0){
    handleCommand(command);
  }
}
//parses the command and executes it
void handleCommand(String command){
  const char *cmd = command.c_str();
  char *f = strtok(cmd, ':');
  char *speed = strtok(NULL, ':');
  int fan = (int)fan;
  
  switch(fan){
    case 0:
      fan1.set(speed);
      fan2.set(speed);
      fan3.set(speed);
      fan4.set(speed);
    break;
    case 1:
      fan1.set(speed);
    break;
    case 2:
      fan2.set(speed);
    break;
    case 3:
      fan3.set(speed);
    break;
    case 4:
      fan4.set(speed);
    break;
  }
}

