#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int pwnPin, int in1Pin, int in2Pin)
{
	pinMode(pwnPin, OUTPUT);
	pinMode(in1Pin, OUTPUT);
	pinMode(in2Pin, OUTPUT);

	pinPwn = pwnPin;
	pinIn1 = in1Pin;
	pinIn2 = in2Pin;
}

void Motor::vel(int velocity)
{
	int x = map(velocity, -100, 100, -255, 255);

	if (x < 0)
	{
		x *= -1;
	    move(pinPwn, pinIn2, pinIn1, x);
	}
	
	else move (pinPwn, pinIn1, pinIn2, x);
}

void Motor::raw_vel(int velocity)
{
	move(pinPwn, pinIn1, pinIn2, velocity);
}

void Motor::move(int pwn, int in1, int in2, int velocity)
{
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	analogWrite(pwn, velocity);
}