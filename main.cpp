#include "introspection_sort.h"

int main() {
    Introsort<Date> darr = Introsort<Date>(5);
    darr.setArray();
    darr.printArray();
    darr.sort();
    darr.printArray();
    Introsort<octal_number> oarr = Introsort<octal_number>(5);
    oarr.setArray();
    oarr.printArray();
    oarr.sort();
    oarr.printArray();
    Introsort<int> iarr = Introsort<int>(5);
    iarr.setArray();
    iarr.printArray();
    iarr.sort();
    iarr.printArray();
    Introsort<double> doublearr = Introsort<double>(5);
    doublearr.setArray();
    doublearr.printArray();
    doublearr.sort();
    doublearr.printArray();
    std::cout << "\nМатьора Ю. І. ІП-71, Лабораторна робота №4, Варіант 17, Рівень Б\n";
}