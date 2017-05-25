/*
 * provides interface to the L298N H bridge motor driver.
 * This board can drive two motors, use PWM etc. Look it up if you want more info.
 * 
 * Author: John Stillwell
 * 
 */

 int enableMotorA;  //ENA
 int directionPin1; //IN1
 int directionPin2; //IN2
 int enableMotorB;  //ENB
 int directionPin3; //IN3
 int directionPin4; //IN4

class L298N
{
  public:
    L298N(int pin);
    void begin(int speed);
    void end();
    void set(int speed);
    int currentSpeed;
  private:
    int _pin;
};
