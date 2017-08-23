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
	digitalWrite(pinIn1, HIGH);
	digitalWrite(pinIn2, LOW);

	int x = map(velocity, -100, 100, -255, 255);
	analogWrite(pinPwn, x);
}

void Motor::raw_vel(int velocity)
{
	digitalWrite(pinIn1, HIGH);
	digitalWrite(pinIn2, LOW);

	analogWrite(pinPwn, velocity);
}