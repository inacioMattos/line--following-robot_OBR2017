#include "Motors.h"
#include "Arduino.h"

Motors::Motors(int numOfMotors, int Pins[][])
{
	n = numOfMotors;

	for (int jk = 0; jk < numOfMotors; jk++)
	{
		pins[0][jk] = Pins[0][jk];
		pins[1][jk] = Pins[1][jk];
		pins[2][jk] = Pins[2][jk];
	}

}

void Motors::velocity(int velocities[])
{
	for (int jk = 0; jk < n; jk++)
	{
		pinPwn = pins[0][jk];
		pinIn1 = pins[1][jk];
		pinIn2 = pins[2][jk];

		vel(velocities[jk]);
	}
}