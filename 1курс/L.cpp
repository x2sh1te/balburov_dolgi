#include <iostream>
#include<windows.h>
#include<cmath>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double initialAmount;
    cout << "Введите начальную сумму: ";
    cin >> initialAmount;

    double rate;
    cout << "Введите ставку: ";
    cin >> rate;

    double targetAmount;
    cout << "Введите целевую сумму: ";
    cin >> targetAmount;

    int yearsCount;
    yearsCount = log(targetAmount) / log(initialAmount * (1 + rate));

    cout << "Период в годах: " << yearsCount;

    return 0;
}