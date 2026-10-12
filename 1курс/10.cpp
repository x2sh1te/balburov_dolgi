#include<windows.h>
#include <iostream>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int element_count;
    cout << "Введите количество элементов: ";
    cin >> element_count;

    int* number_array = new int[element_count];

    cout << "Введите значения элементов: ";
    for (int i = 0; i < element_count; i++) {
        cin >> number_array[i];
    }

    int non_zero_position = 0;

    for (int i = 0; i < element_count; i++) {
        if (number_array[i] != 0) {
            number_array[non_zero_position] = number_array[i];
            non_zero_position++;
        }
    }

    for (int i = non_zero_position; i < element_count; i++) {
        number_array[i] = 0;
    }

    cout << "Результат: ";
    for (int i = 0; i < element_count; i++) {
        cout << number_array[i] << " ";
    }

    delete[] number_array;
    return 0;
}