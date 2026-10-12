#include <iostream>
#include<windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float loan_amount;
	cout << "Введите сумму кредита: ";
	cin >> loan_amount;

	float interest_rate;
	cout << "Введите процентную ставку: ";
	cin >> interest_rate;

	float annual_payment;
	cout << "Введите ежегодный платеж: ";
	cin >> annual_payment;

	int years_count = 0;

	while (loan_amount > 0) {
		loan_amount = loan_amount + loan_amount * (interest_rate / 100);
		loan_amount = loan_amount - annual_payment;
		years_count = years_count + 1;
	}

	cout << "Кредит будет погашен за: " << years_count << " лет";

	return 0;
}