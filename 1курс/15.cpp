#include <iostream>
using namespace std;

int getFibonacciValue(int position) {
    if (position == 1) return 0;
    if (position == 2) return 1;

    int prev_prev = 0;
    int prev = 1;
    int current;

    for (int i = 3; i <= position; ++i) {
        current = prev_prev + prev;
        prev_prev = prev;
        prev = current;
    }
    return current;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int sequence_position;
    cout << "Введите позицию в последовательности: ";
    cin >> sequence_position;

    cout << "Число Фибоначчи на позиции " << sequence_position
        << ": " << getFibonacciValue(sequence_position) << endl;

    return 0;
}
