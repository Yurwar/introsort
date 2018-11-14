//
// Created by yurii on 10.11.18.
//

#include "date.h"
#include <iostream>

int Date::convertToJDN() {
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;

    int JDN = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
    return JDN;
}

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
    this->JDN = convertToJDN();
}

Date::Date() {
    this->day =1;
    this->month=1;
    this->year=1970;
    this->JDN = convertToJDN();
}

void Date::printDate() {
    std::cout << this->day << '.' << this->month << '.' << this->year;
}

bool Date::operator>(Date &a) {
    return this->JDN > a.JDN;
}

bool Date::operator<(Date &a) {
    return this->JDN < a.JDN;
}

bool Date::operator<=(Date &a) {
    return this->JDN <= a.JDN;
}

bool Date::operator>=(Date &a) {
    return this->JDN >= a.JDN;
}

bool Date::operator==(Date &a) {
    return this->JDN == a.JDN;
}
