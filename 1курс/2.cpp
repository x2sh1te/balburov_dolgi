#include <iostream>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int array_length = 3;
    int binary_array[array_length] = { 1, 0, 1 }; 

    cout << "Исходное двоичное число: ";
    for (int i = 0; i < array_length; i++) {
        cout << binary_array[i];
    }

    bool has_carryover = true;


    for (int i = array_length - 1; i >= 0; i--) {
        if (binary_array[i] == 0) {
            binary_array[i] = 1;
            has_carryover = false;
            break;
        }
        else {
            binary_array[i] = 0;
        }
    }

    cout << endl << "Результат M+1: ";

    if (has_carryover) {

        cout << "1";
        for (int i = 0; i < array_length; i++) {
            cout << binary_array[i];
        }
    }
    else {

        for (int i = 0; i < array_length; i++) {
            cout << binary_array[i];
        }
    }

    return 0;
}