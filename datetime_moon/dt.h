#pragma once
#pragma once
#include <string>
class DateTime {
private:
    //int day;
    //int month;
    //int year;
    //int hour, minute, second;
    bool isLeapYear(int y) const;
    int daysInMonth(int m, int y) const;
    bool isValidDate(int d, int m, int y) const;
    long long toDays() const;
    int getWeekday() const;

public:
    int day;
    int month;
    int year;
    int hour, minute, second;
    DateTime();
    DateTime(int d, int m, int y);
    void inputDate();
    void parse(const char* s);

    void print() const; // yyyy-MM-ddThh:mm:ss
    void print2() const; //yyyy-MM-dd
    void printTime() const;
    bool isValid() const;
    void printWeekday() const;

    long long operator-(const DateTime& other) const;
    DateTime operator+(int days) const;

    bool operator==(const DateTime& other) const;
    bool operator>(const DateTime& other) const;
    bool operator>=(const DateTime& other) const;
    bool operator<(const DateTime& other) const;
    bool operator<=(const DateTime& other) const;

};
