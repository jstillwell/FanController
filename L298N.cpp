#include "L298N.h"

L298N::L298N(int ena, int in1, int in2, int enb, int in3, int in4){
  _enA = ena;
  _enB = enb;
  _in1 = in1;
  _in2 = in2;
  _in3 = in3;
  _in4 = in4;
}

void L298N::begin(int speed, Direction direction){
  if(direction == 0){
    digitalWrite(_in1, HIGH);
    digitalWrite(_in2, LOW);
  } else {
    digitalWrite(_in1, LOW);
    digitalWrite(_in2, HIGH);
  }
  analogWrite(_enA, speed);
}
void L298N::end(){
  analogWrite(_enA, 0);
}
void L298N::set(int speed){
  analogWrite(_enA, speed);
}

