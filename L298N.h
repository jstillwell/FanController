/*
 * provides interface to the L298N H bridge motor driver.
 * This board can drive two motors, use PWM etc. Look it up if you want more info.
 * 
 * Author: John Stillwell
 * 
 */

 enum Direction {
  Forward,
  Backward
 }

class L298N
{
  public:
    L298N(int ena, int in1, int in2, int enb, int in3, int in4);
    void begin(int speed, Direction direction);
    void end();
    void set(int speed);
  private:
    int currentSpeed;
    int _enA;
    int _in1;
    int _in2;
    int _enB;
    int _in3;
    int _in4;
};
