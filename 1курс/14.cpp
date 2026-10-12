#include <iostream>
#include<locale.h>
using namespace std;

bool checkDigitSum(int number, int target_sum) {
    if (number == 0)
        return target_sum == 0;
    return checkDigitSum(number / 10, target_sum - number % 10);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int input_number;
    int expected_sum;

    cin >> input_number >> expected_sum;

    cout << (checkDigitSum(input_number, expected_sum) ?
        "Сумма цифр соответствует" :
        "Сумма цифр не соответствует");

    return 0;
}