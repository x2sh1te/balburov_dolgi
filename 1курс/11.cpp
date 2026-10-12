#include<iostream> 
#include<windows.h> 
using namespace std;

int computeGCD(int num1, int num2) {
	if (num2 == 0) {
		return num1;
	}
	return computeGCD(num2, num1 % num2);
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int first_number, second_number;
	cout << "Введите первое целое число: ";
	cin >> first_number;
	cout << "Введите второе целое число: ";
	cin >> second_number;

	cout << "Наибольший общий делитель: " << computeGCD(first_number, second_number) << endl;

	return 0;
}