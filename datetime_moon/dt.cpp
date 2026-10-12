#define _CRT_SECURE_NO_WARNINGS
#include"dt.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include<cstring>
using namespace std;

DateTime::DateTime() {
	day = 1;
	month = 1;
	year = 1900;
	hour = 0;
	minute = 0;
	second = 0;
}
DateTime::DateTime(int d, int m, int y) {
	day = d;
	month = m;
	year = y;
	hour = 0;
	minute = 0;
	second = 0;
}

bool DateTime::isLeapYear(int y) const {
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int DateTime::daysInMonth(int m, int y) const {
	int d[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (m == 2) return isLeapYear(y) ? 29 : 28;
	return d[m];
}
bool DateTime::isValidDate(int d, int m, int y) const {
	if (y < 1 || y>9999) return false;
	if (m < 1 || m>12) return false;
	if (d < 1 || d>31) return false;
	return d <= daysInMonth(m, y);
}
long long DateTime::toDays() const {
	long long total = 0;
	for (int y = 1; y < year; y++) {
		total += isLeapYear(y) ? 366 : 365;
	}
	for (int m = 1; m < month; m++) {
		total += daysInMonth(m, year);
	}
	total += day;
	return total;
}
int DateTime::getWeekday() const {
	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + 12 * a - 2;
	return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
}

void DateTime::inputDate() {
	int d, m, y;
	char t1, t2;
	cout << "Введите дату(формат дд.мм.гггг): ";
	cin >> d >> t1 >> m >> t2 >> y;
	day = d;
	month = m;
	year = y;
	hour = 0;
	minute = 0;
	second = 0;
	if (isValidDate(d, m, y)) {
		day = d;
		month = m;
		year = y;
		cout << "Дата введена корректно";
	}
	else {
		cout << "Дата введена некорректно";
	}
}
void DateTime::parse(const char* s) {
	if (!s || s[0] == '\0') return;
	int y = 1900, m = 1, d = 1;
	int h = 0, minn = 0, sec = 0;

	char buf[100];
	strncpy(buf, s, sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';

	char* t = strchr(buf, 'T');
	if (t) *t = ' ';

	if (sscanf(buf, "%d-%d-%d %d:%d:%d", &y, &m, &d, &h, &minn, &sec) == 6) {
	}
	else if (sscanf(buf, "%d-%d-%d", &y, &m, &d) == 3) {

	}
	else if (sscanf(buf, "%d:%d:%d", &h, &minn, &sec) == 3) {
		day = 1;
		month = 1;
		year = 1900;
		hour = h;
		minute = minn;
		second = sec;
		return;
	}
	else {
		return;
	}
	day = d;
	month = m;
	year = y;
	hour = h;
	minute = minn;
	second = sec;
}

void DateTime::print() const {
	cout << setfill('0') << setw(4) << year << "-"
		<< setw(2) << month << "-" << setw(2) << day << "T"
		<< setw(2) << hour << ":"
		<< setw(2) << minute << ":"
		<< setw(2) << second;
}
void DateTime::print2() const {
	cout << setfill('0') << setw(4) << year << "-"
		<< setw(2) << month << "-" << setw(2) << day;
}
void DateTime::printTime() const {
	cout << setfill('0') << setw(2) << hour << ":"
		<< setw(2) << minute << ":"
		<< setw(2) << second;
}
bool DateTime::isValid() const {
	return isValidDate(day, month, year);
}
void DateTime::printWeekday() const {
	const char* names[7] = { "Воскресенье", "Понедельник", "Вторник", "Среда",
							"Четверг", "Пятница", "Суббота" };
	cout << names[getWeekday()];
}
long long DateTime::operator-(const DateTime& other) const {
	return toDays() - other.toDays();
}
DateTime DateTime::operator+(int days) const {
	DateTime res = *this;
	res.day += days;
	while (res.day > res.daysInMonth(res.month, res.year)) {
		res.day -= res.daysInMonth(res.month, res.year);
		res.month++;
		if (res.month > 12) {
			res.month = 1;
			res.year++;
		}
	}
	return res;
}
bool DateTime::operator==(const DateTime& other) const {
	return year == other.year &&
		month == other.month &&
		day == other.day &&
		hour == other.hour &&
		minute == other.minute &&
		second == other.second;
}

bool DateTime::operator>(const DateTime& other) const {
	if (year != other.year) return year > other.year;
	if (month != other.month) return month > other.month;
	if (day != other.day) return day > other.day;
	if (hour != other.hour) return hour > other.hour;
	if (minute != other.minute) return minute > other.minute;
	return second > other.second;
}

bool DateTime::operator>=(const DateTime& other) const {
	return *this > other || *this == other;
}

bool DateTime::operator<(const DateTime& other) const {
	return !(*this >= other);
}

bool DateTime::operator<=(const DateTime& other) const {
	return !(*this > other);
}