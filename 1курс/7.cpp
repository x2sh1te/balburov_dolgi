#include<windows.h>
#include<algorithm>
#include <iostream>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int element_count;
    cout << "Введите количество элементов: ";
    cin >> element_count;

    int* number_sequence = new int[element_count];

    cout << "Введите последовательность чисел: ";
    for (int i = 0; i < element_count; i++) {
        cin >> number_sequence[i];
    }

    sort(number_sequence, number_sequence + element_count);

    for (int i = 0; i < element_count - 1; i++) {
        if (number_sequence[i] == number_sequence[i + 1]) {
            cout << "Найдено повторяющееся значение: " << number_sequence[i] << endl;
            delete[] number_sequence;
            return 0;
        }
    }

    cout << "Повторяющихся значений не обнаружено" << endl;
    delete[] number_sequence;

    return 0;
}