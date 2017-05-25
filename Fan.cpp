#include "Arduino.h"
#include "Fan.h"

Fan::Fan(int pin){
  _pin = pin;
  pinMode(pin, OUTPUT);
  analogWrite(pin, 0);
}

void Fan::begin(int speed){
  analogWrite(_pin, speed);
  currentSpeed = speed;
}

void Fan::end(){
  while(currentSpeed > 0){
    int newSpeed = currentSpeed-5;
    analogWrite(_pin, newSpeed);  
    currentSpeed = newSpeed;
  }
  currentSpeed = 0;
}

void Fan::set(int speed){
  if(speed > currentSpeed){
     for(int i=currentSpeed; i > speed; i+5){
       analogWrite(_pin, i);
     }
  } else {
    for(int i=currentSpeed; i < speed; i-5){
       analogWrite(_pin, i);
     } 
  }
  currentSpeed = speed;
}
