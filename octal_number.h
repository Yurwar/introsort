//
// Created by yurii on 10.11.18.
//

#ifndef INTROSORT_OCTAL_NUMBER_H
#define INTROSORT_OCTAL_NUMBER_H

#include <stack>

class octal_number {
private:
    std::stack<int> st;
    int number;
    int convertToOct(int intNum);
public:
    octal_number();
    octal_number(int octNumber);
    int getOctNumber();
    void setIntNumber(int intNumber);
    void setOctNumber(int octNumber);
    bool operator<(octal_number &a);
    bool operator>(octal_number &a);
    bool operator<=(octal_number &a);
    bool operator>=(octal_number &a);
    bool operator==(octal_number &a);
};


#endif //INTROSORT_OCTAL_NUMBER_H
