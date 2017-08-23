#ifndef SServo_h
#define SServo_h

#include "Arduino.h"
#include <Servo.h>

class SServo
{
public:
	SServo(int pin);
	~SServo();
	int read();
	void setPos(int position);
private:
	int pinServo = 0;
	int positionServo = -1;
};




#endif