#include <iostream>
#include <wiringPi.h>
using namespace std;

int number(int input)   //Keeps Number within 0 and 9
{
	int output = input;

	if (input > 9)
	{
		output = 0;
	}

	return output;
}

int trigger()
{
	do
	{
		if (digitalRead(0))  //Waiting for Clock Tick
		{
			return 1;
			break;
		}

	} while (1);

}

void nixieout(int number, int pin[4])   //Number to Microcontroller Logic
{

	int A = 0, B = 0, C = 0, D = 0;

	switch (number)
	{

	case 0: A = 0, B = 0, C = 0, D = 0;
	case 1: A = 1, B = 0, C = 0, D = 0;
	case 2: A = 0, B = 1, C = 0, D = 0;
	case 3: A = 1, B = 1, C = 0, D = 0;
	case 4: A = 0, B = 0, C = 1, D = 0;
	case 5: A = 1, B = 0, C = 1, D = 0;
	case 6: A = 0, B = 1, C = 1, D = 0;
	case 7: A = 1, B = 1, C = 1, D = 0;
	case 8: A = 0, B = 0, C = 0, D = 1;
	case 9: A = 1, B = 0, C = 0, D = 1;

	}

	digitalWrite(pin[0], A);  //Output to the Microcontroller
	digitalWrite(pin[1], B);
	digitalWrite(pin[2], C);
	digitalWrite(pin[3], D);

	cout << A;  //Output to the Microcontroller
	cout << B;
	cout << C;
	cout << D;

}

int main()

{
	int num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0;
	int tick;
	int ip;
	int sec1[4] = {1,2,3,4};
	int sec2[4] = {5,6,7,8};
	int min1[4] = {9,10,11,12};
	int min2[4] = {13,14,15,16};
	int hr1[4] = {17,18,19,20};
	int hr2[4] = {21,22,23,24};

	pinMode(0, INPUT);
	pinMode(25, INPUT);
	pinMode(1, INPUT);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(13, OUTPUT);
	pinMode(14, OUTPUT);
	pinMode(15, OUTPUT);
	pinMode(16, OUTPUT);
	pinMode(17, OUTPUT);
	pinMode(18, OUTPUT);
	pinMode(19, OUTPUT);
	pinMode(20, OUTPUT);
	pinMode(21, OUTPUT);
	pinMode(22, OUTPUT);
	pinMode(23, OUTPUT);
	pinMode(24, OUTPUT);

	ip = digitalRead(25);

	do
	{


		do
		{


			num1 = number(num1);  //Clock Values
			num2 = number(num2);
			num3 = number(num3);
			num4 = number(num4);
			num5 = number(num5);
			num6 = number(num6);

			nixieout(num1, sec1);		//Value Sent to Logic Converter
			nixieout(num2, sec2);
			nixieout(num3, min1);
			nixieout(num4, min2);
			nixieout(num5, hr1);
			nixieout(num6, hr2);

			cout << num1;

			num1++;
			num2++;
			num3++;
			num4++;
			num5++;
			num6++;

			tick = trigger();        //Clock Tick

		} while (tick == 1);

	} while (1);
	//cout << x;
	return 0;
}


