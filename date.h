//
// Created by yurii on 10.11.18.
//

#ifndef INTROSORT_DATE_H
#define INTROSORT_DATE_H


class Date {
private:
    int convertToJDN();
public:
    int day;
    int month;
    int year;
    int JDN;
    Date(int day, int month, int year);
    Date();
    void printDate();

    bool operator>(Date &a);
    bool operator<(Date &a);
    bool operator<=(Date &a);
    bool operator>=(Date &a);
    bool operator==(Date &a);
};


#endif //INTROSORT_DATE_H
