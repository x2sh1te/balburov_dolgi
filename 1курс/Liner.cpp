#include <iostream>
#include<windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double inputValue;
	cout << "Укажите значение в радианах: ";
	cin >> inputValue;

	double degrees;
	degrees = (inputValue * 180) / M_PI;

	double minutes;
	minutes = inputValue * (60 * 180) / M_PI;

	double seconds;
	seconds = inputValue * (3600 * 180) / M_PI;

	cout << "Угол в градусной мере: " << degrees << endl;
	cout << "Угол в угловых минутах: " << minutes << endl;
	cout << "Угол в угловых секундах: " << seconds << endl;

	return 0;
}