#include <iostream>
#include <windows.h>
#include <cmath> 
#define M_PI 3.14159265358979323846
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Анализ функции y = x^4" << endl;
    double tolerance = 1e-6;
    bool is_even = true;
    bool is_odd = true;

    for (double x = -5; x <= 5; x += 0.5) {
        double f_x = x * x * x * x;
        double f_minus_x = (-x) * (-x) * (-x) * (-x);

        if (fabs(f_x - f_minus_x) < tolerance) {
            is_odd = false;
            break;
        }
        if (fabs(f_x + f_minus_x) < tolerance) {
            is_even = false;
            break;
        }
    }

    if (is_even) {
        cout << "Функция является четной" << endl;
    }
    else {
        cout << "Функция не является четной" << endl;
    }

    cout << "Анализ функции y = tg(x)" << endl;
    bool tangent_even = true;
    bool tangent_odd = true;

    for (double x = -M_PI; x <= M_PI; x += 0.5) {
        double y_x = tan(x);
        double y_minus_x = tan(-x);

        if (fabs(y_x - y_minus_x) < tolerance) {
            tangent_odd = false;
            break;
        }
        if (fabs(y_x + y_minus_x) < tolerance) {
            tangent_even = false;
            break;
        }
        if (y_minus_x != -y_x) {
            tangent_odd = false;
            break;
        }
    }

    if (tangent_odd) {
        cout << "Функция y = tan(x) является нечетной" << endl;
    }
    else {
        cout << "Функция y = tan(x) не является нечетной" << endl;
    }

    cout << "Анализ функции y = e^x" << endl;
    bool exponential_even = true;

    for (double x = -5; x <= 5; x += 0.1) {
        double f_x = exp(x);
        double f_minus_x = exp(-x);

        if (f_minus_x != f_x) {
            exponential_even = false;
            break;
        }
        if (fabs(f_x - f_minus_x) < tolerance) {
            exponential_even = false;
            break;
        }
        if (fabs(f_x + f_minus_x) < tolerance) {
            is_even = false;
            break;
        }
    }

    if (exponential_even) {
        cout << "Функция y = e^x является четной" << endl;
    }
    else {
        cout << "Функция y = e^x не является четной" << endl;
    }

    return 0;
}