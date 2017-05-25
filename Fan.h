/*  
 *   Fan header file for Fan class
 *  Sets up a Fan with the pins set and the initial state set to off.
    
 *   Author: John Stillwell
    
 *   BLACK---GND
 *  YELLOW---12V
 *  GREEN---TACHOMETER
 *  BLUE---PWM
*/

#include "Arduino.h"

#ifndef Fan_h
#define Fan_h

class Fan
{
  public:
    Fan(int pin);
    void begin(int speed);
    void end();
    void set(int speed);
    int currentSpeed;
  private:
    int _pin;
};

#endif
