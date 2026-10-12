#include <iostream>
#include<windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int numbers_list[8000];
    int numbers_count = 0;

    for (int current_number = 1000; current_number < 10000; current_number++) {
        int digit1 = current_number / 1000;
        int digit2 = current_number / 100 % 10;
        int digit3 = current_number / 10 % 10;
        int digit4 = current_number % 10;

        if (digit1 != digit2 && digit1 != digit3 && digit1 != digit4 &&
            digit2 != digit3 && digit2 != digit4 && digit3 != digit4) {
            numbers_list[numbers_count++] = current_number;
        }
    }

    cout << "Четырехзначные числа без повторяющихся цифр: ";
    for (int i = 0; i < numbers_count; i++) {
        cout << numbers_list[i] << " ";
    }

    return 0;
}