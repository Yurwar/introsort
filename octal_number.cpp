//
// Created by yurii on 10.11.18.
//

#include "octal_number.h"
#include <iostream>
#include <string>

int octal_number::convertToOct(int intNum) {
    while(intNum / 8 != 0) {
        st.push(intNum % 8);
        intNum = intNum / 8;
    }
    st.push(intNum);
    std::string strOctNum;
    while(!st.empty()) {
        strOctNum += std::to_string(st.top());
        st.pop();
    }
    int octNum = stoi(strOctNum);
    return octNum;
}

octal_number::octal_number() {}

octal_number::octal_number(int octNumber) {
    number = octNumber;
}

int octal_number::getOctNumber() {
    return number;
}

void octal_number::setIntNumber(int intNumber) {
    number = convertToOct(intNumber);
}

void octal_number::setOctNumber(int octNumber) {
    number = octNumber;
}

bool octal_number::operator<(octal_number &a) {
    return this->number < a.getOctNumber();
}

bool octal_number::operator>(octal_number &a) {
    return this->number > a.getOctNumber();
}

bool octal_number::operator<=(octal_number &a) {
    return this->number <= a.getOctNumber();
}

bool octal_number::operator>=(octal_number &a) {
    return this->number >= a.getOctNumber();
}

bool octal_number::operator==(octal_number &a) {
    return this->number == a.getOctNumber();
}
