#include "Arduino.h"
#include "SServo.h"

SServo::SServo(int pin)
{
	pinServo = pin;
	Servo s;

	s.attach(pin);
}

SServo::read()
{
	return positionServo;
}

SServo::setPos(int position)
{
	if (position >= 0 || position <= 180)
	{
		s.write(position);
	}
}