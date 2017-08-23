#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{	
public:
	Motor(int pwnPin, int in1Pin, int int2Pin);
	void vel(int velocity);
	void raw_vel(int velocity);

private:
	int pinPwn;
	int pinIn1;
	int pinIn2;
};

#endif