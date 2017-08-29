#include "Arduino.h"
#include "Encoder.h"

Encoder::Encoder(int pin)
{
	p = pin;
	pinMode(p, INPUT);

	x = LOW;
	lTime = millis();
}


bool Encoder::pulse()
{
	int n = digitalRead(p);

	if (x == LOW && n == HIGH)
	{
		x = n;
		return true;
	}

	else
	{
		x = n;
		return false;
	}
}

bool Encoder::isMoving(int &cont)
{
	unsigned long cTime = millis();

	if (cTime - lTime > 250 && cont > 0)
	{
		double d = (cTime - lTime) / 250;
		s = cont / d;

		lTime = cTime;
		cont = 0;
		return true;
	}

	return false;
}