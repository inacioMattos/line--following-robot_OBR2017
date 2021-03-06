#include "Arduino.h"
#include "SServo.h"

SServo::SServo(int pin)
{
	pinServo = pin;

	s.attach(pin);
}

int SServo::read()
{
	return positionServo;
}

void SServo::setPos(int position)
{
	if (position >= 0 || position <= 180)
	{
		s.write(position);
		positionServo = position;
	}
}
