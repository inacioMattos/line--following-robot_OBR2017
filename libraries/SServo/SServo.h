#ifndef SServo_h
#define SServo_h

#include "Servo.h"
#include "Arduino.h"

class SServo
{
public:
	SServo(int pin);
	//~SServo();
	int read();
	void setPos(int position);
private:
	int pinServo;
	int positionServo = -1;
	Servo s;
};




#endif