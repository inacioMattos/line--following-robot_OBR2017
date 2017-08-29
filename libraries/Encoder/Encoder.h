#ifndef Encoder_h
#define Encoder_h

#include "Arduino.h"

class Encoder
{
public:
	Encoder(int pin);
	bool pulse();
	bool isMoving(int &cont);
	double s = 0;
	
private:
	int p, x;
	unsigned long lTime;
};

#endif