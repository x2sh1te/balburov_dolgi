#include<windows.h>
#include <iostream>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int sequence_length;
    cout << "Введите количество элементов последовательности: ";
    cin >> sequence_length;

    int* number_series = new int[sequence_length];

    cout << "Введите числовую последовательность: ";
    for (int i = 0; i < sequence_length; i++) {
        cin >> number_series[i];
    }

    int longest_zero_run = 0;
    int current_zero_run = 0;

    for (int i = 0; i < sequence_length; i++) {
        if (number_series[i] == 0) {
            current_zero_run++;
        }
        else {
            if (current_zero_run > longest_zero_run) {
                longest_zero_run = current_zero_run;
            }
            current_zero_run = 0;
        }
    }

    if (current_zero_run > longest_zero_run) {
        longest_zero_run = current_zero_run;
    }

    cout << "Максимальная длина непрерывной последовательности нулей: " << longest_zero_run << endl;

    delete[] number_series;
    return 0;
}