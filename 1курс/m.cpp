#include <iostream>
#include<windows.h>
#include<cmath>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int hours_input, minutes_input, seconds_input;
    cout << "Введите часы, минуты и секунды: ";
    cin >> hours_input >> minutes_input >> seconds_input;

    double total_seconds = hours_input * 3600 + minutes_input * 60 + seconds_input;

    int total_minutes = round(total_seconds / 60);
    int hours_from_minutes = total_minutes / 60;
    int minutes_from_minutes = total_minutes % 60;

    int rounded_hours = round(total_seconds / 3600.0);

    cout << "Округленное время до минут: " << hours_from_minutes
        << "ч " << minutes_from_minutes << "мин" << endl;
    cout << "Округленное время до часов: " << rounded_hours << "ч";

    return 0;
}