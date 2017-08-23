#include "Motors.h"
#include "Arduino.h"

Motors::Motors(int pwn_motor1, int in1_motor1, int in2_motor1, int pwn_motor2, int in1_motor2, int in2_motor2, int pwn_motor3, int in1_motor3, int in2_motor3, int pwn_motor4, int in1_motor4, int in2_motor4)
{

	pins[0][0] = pwn_motor1;
	pins[1][0] = in1_motor1;
	pins[2][0] = in2_motor1;

	pins[0][0] = pwn_motor2;
	pins[1][0] = in1_motor2;
	pins[2][0] = in2_motor2;

	pins[0][0] = pwn_motor3;
	pins[1][0] = in1_motor3;
	pins[2][0] = in2_motor3;

	pins[0][0] = pwn_motor4;
	pins[1][0] = in1_motor4;
	pins[2][0] = in2_motor4;

	

	for (int jk = 0; jk < 4; jk++)
	{
		pinMode(pins[0][jk], OUTPUT);

		pinMode(pins[1][jk], OUTPUT);
		
		pinMode(pins[2][jk], OUTPUT);
	}

}

void Motors::vel(int velocities[4])
{
	for (int jk = 0; jk < 4; jk++)
	{
		int pinPwn = pins[0][jk];
		int pinIn1 = pins[1][jk];
		int pinIn2 = pins[2][jk];

		Motor m(pinPwn, pinIn1, pinIn2);
		m.vel(velocities[jk]);
	}
}