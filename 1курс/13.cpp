#include<locale.h>
#include <iostream>
using namespace std;

void factorizeNumber(int number) {
    if (number == 1) return;

    for (int divisor = 2; divisor <= number; divisor++) {
        if (number % divisor == 0) {
            cout << divisor << " ";
            factorizeNumber(number / divisor);
            return;
        }
    }
}

int main() {
    int input_number;
    cin >> input_number;
    factorizeNumber(input_number);
    return 0;
}