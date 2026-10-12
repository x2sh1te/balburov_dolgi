#include <iostream>
#include<windows.h>
#include <cmath> 
#define M_PI 3.14159265358979323846
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double tolerance = 1e-6;

    cout << "Анализ функции y = sin²x" << endl;
    bool is_periodic = true;

    for (double x = 0; x <= 5 * M_PI; x += 0.1) {
        double f_x = pow(sin(x), 2);
        double f_x_plus_pi = pow(sin(x + M_PI), 2);

        if (fabs(f_x - f_x_plus_pi) > tolerance) {
            is_periodic = false;
            break;
        }
    }

    if (is_periodic) {
        cout << "Функция периодическая" << endl;
    }
    else {
        cout << "Функция не периодическая" << endl;
    }

    cout << endl << "Анализ функции y = tg(x)" << endl;

    for (double x = 0; x <= 5 * M_PI; x += 0.1) {
        double f_x = tan(x);
        double f_x_plus_pi = tan(x + M_PI);

        if (cos(x) == 0) {
            cout << "Тангенс не определен в точках, где cos(x) = 0 (разрыв)" << endl;
        }
        else {
            cout << "tan(" << x << ") = " << tan(x) << endl;
        }

        if (fabs(f_x - f_x_plus_pi) > tolerance) {
            cout << "Функция не периодическая" << endl;
        }
        else {
            cout << "Функция периодическая" << endl;
        }
    }

    cout << endl << "Анализ функции (1/x) * sin(x)" << endl;

    for (double x = 0.1; x <= 5 * (2 * M_PI); x += 0.1) {
        double f_x = (1 / x) * sin(x);
        double f_x_plus_pi = (1 / (x + M_PI)) * sin(x + M_PI);

        if (x == 0) {
            cout << "Функция не определена в точке 0 (разрыв)" << endl;
        }
        else {
            cout << "(1/x)*sin(x) при x=" << x << " = " << (1 / x) * sin(x) << endl;
        }

        if (fabs(f_x - f_x_plus_pi) > tolerance) {
            cout << "Функция не периодическая" << endl;
        }
        else {
            cout << "Функция периодическая" << endl;
        }
    }

    return 0;
}