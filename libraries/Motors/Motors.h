#ifndef Motors_h
#define Motors_h

#include "Arduino.h"
#include "Motor.h"

class Motors: protected Motor
{
public:
	Motors(int numOfMotors, int Pins[][]);

	void velocity(int velocity1);
	void velocity(int velocity1, int velocity2);
	void velocity(int velocity1, int velocity2, int velocity3);
	void velocity(int velocity1, int velocity2, int velocity3, int velocity4);

private:
	int pins[3][4] {};
	int n;
};

#endif