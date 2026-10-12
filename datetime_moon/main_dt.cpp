#define _CRT_SECURE_NO_WARNINGS
#include "dt.h"
#include <iostream>
#include <clocale>
#include <fstream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Полная демонстрация" << endl;

    cout << "1. Проверка разных форматов ввода:" << endl;

    DateTime d1;
    d1.parse("2025-04-05");
    cout << "Только дата:           "; d1.print(); cout << endl;

    DateTime d2;
    d2.parse("2021-12-21T07:54:34");
    cout << "Дата + время:";
    d2.print();
    cout << endl;

    DateTime d3;
    d3.parse("2025-04-05T15:30:00");
    cout << "Дата + время (другое): ";
    d3.print();
    cout << endl;

    DateTime d4;
    d4.parse("14:30:45");
    cout << "Только время:";
    d4.print();
    cout << endl;

    cout << "2. Проверка корректности:" << endl;
    DateTime bad;
    bad.parse("2025-02-30");
    cout << "Некорректная дата (30 февраля): "; bad.print();
    cout << "  ? Корректна? " << (bad.isValid() ? "Да" : "Нет") << endl;


    cout << "3. Основные операции:" << endl;
    cout << "Разница d3 - d2 = " << (d3 - d2) << " дней\n";

    DateTime d5 = d3 + 10;
    cout << "d3 + 10 дней = "; d5.print(); cout << endl;

    cout << "4. Сравнения:" << endl;
    cout << "d3 > d2  ? " << (d3 > d2 ? "Да" : "Нет") << endl;
    cout << "d3 == d3 ? " << (d3 == d3 ? "Да" : "Нет") << endl;
    cout << "d2 <= d3 ? " << (d2 <= d3 ? "Да" : "Нет") << endl;


    cout << "5. День недели:" << endl;
    cout << "Для даты "; d3.print2();
    cout << " — "; d3.printWeekday(); cout << endl;


    cout << "Восход, кульминация и заход Луны ";

    DateTime today(1, 1, 2006);

    cout << "Выбрана дата: ";
    today.print2();
    cout << "\n\n";

    ifstream file("Moon/moon2006.dat");
    char line[500];
    file.getline(line, sizeof(line)); 

    DateTime voshod, culmin, zahod;
    double max_el = -1000.0;
    bool found_voshod = false;
    bool found_zahod = false;
    int count = 0;

    double prev_el = -1000.0;
    DateTime prev_dt;

    while (file.getline(line, sizeof(line))) {
        char* token = strtok(line, " \t\r\n");
        if (!token) continue;

        int ymd = atoi(token);
        token = strtok(NULL, " \t\r\n");
        if (!token) continue;
        int hms = atoi(token);

        strtok(NULL, " \t\r\n"); 
        strtok(NULL, " \t\r\n"); 

        token = strtok(NULL, " \t\r\n");
        if (!token) continue;
        double el = atof(token);

        count++;

        int y = ymd / 10000;
        int m = (ymd / 100) % 100;
        int d = ymd % 100;

        int hh = hms / 10000;
        int mm = (hms / 100) % 100;
        int ss = hms % 100;

        DateTime curr(d, m, y);
        curr.hour = hh;
        curr.minute = mm;
        curr.second = ss;

        if (count == 1) {
            prev_el = el;
            prev_dt = curr;
            culmin = curr;
            max_el = el;
            continue;
        }

        // Восход
        if (!found_voshod && prev_el < 0.0 && el >= 0.0) {
            voshod = curr;
            found_voshod = true;
        }

        // Заход 
        if (!found_zahod && found_voshod && prev_el >= 0.0 && el < 0.0) {
            zahod = curr;
            found_zahod = true;
        }

        // Кульминация
        if (el > max_el) {
            max_el = el;
            culmin = curr;
        }

        prev_el = el;
        prev_dt = curr;
    }

    file.close();

    cout << "Дата: ";
    today.print2();
    cout << endl;

    cout << "Восход Луны: ";
    if (found_voshod) voshod.printTime();
    cout << endl;

    cout << "Кульминация Луны: ";
    culmin.printTime();
    cout << endl;

    cout << "Заход Луны: ";
    if (found_zahod) zahod.printTime();
    cout << endl;

    system("pause");
    return 0;

}