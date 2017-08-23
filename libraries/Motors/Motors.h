#ifndef Motors_h
#define Motors_h

#include "Arduino.h"
#include "Motor.h"

class Motors
{
public:
	Motors(int pwn_motor1, int in1_motor1, int in2_motor1, int pwn_motor2, int in1_motor2, int in2_motor2, int pwn_motor3, int in1_motor3, int in2_motor3, int pwn_motor4, int in1_motor4, int in2_motor4);

	void vel(int velocities[4]);

private:
	int pins[3][4] {};
};

#endif