#include<locale.h>
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const int MAX_ELEMENTS = 100;
    int array_size;
    int numbers_array[MAX_ELEMENTS];

    cout << "Введите количество элементов (не более " << MAX_ELEMENTS << "): ";
    cin >> array_size;

    cout << "Введите значения элементов: ";
    for (int i = 0; i < array_size; i++) {
        cin >> numbers_array[i];
    }

    int max_symmetric_length = 0;

    for (int left_index = 0; left_index < array_size; left_index++) {
        for (int right_index = left_index; right_index < array_size; right_index++) {
            bool is_symmetric = true;
            int current_length = right_index - left_index + 1;

            for (int offset = 0; offset < current_length / 2; offset++) {
                if (numbers_array[left_index + offset] != numbers_array[right_index - offset]) {
                    is_symmetric = false;
                    break;
                }
            }

            if (is_symmetric && current_length > max_symmetric_length) {
                max_symmetric_length = current_length;
            }
        }
    }

    cout << "Максимальная длина симметричного отрезка = " << max_symmetric_length << endl;

    return 0;
}