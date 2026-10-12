#include <iostream>
#include<windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int degrees_input, minutes_input, seconds_input;
    cout << "Введите градусы, минуты и секунды: ";
    cin >> degrees_input >> minutes_input >> seconds_input;

    float pi_value = 3.14;
    double total_degrees, radians_result;

    total_degrees = (degrees_input + ((minutes_input / 60.0) + (seconds_input / 3600.0)));
    radians_result = (total_degrees * pi_value) / 180;

    cout << "Величина угла в радианах: " << radians_result;

    return 0;
}