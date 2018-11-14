//
// Created by yurii on 10.11.18.
//

#ifndef INTROSORT_INTROSPECTION_SORT_H
#define INTROSORT_INTROSPECTION_SORT_H

#include "date.h"
#include "octal_number.h"
#include <iostream>
#include <cmath>

template <class T>
class Introsort {
private:
    T *arr;
    int arrSize;

    void swap(T &a, T &b);
    int partition(int p, int r);
    void introsort(int p, int r, int depth);
    void heapify(int n, int i);
    void heapSort(int n);

public:
    Introsort(int size);
    ~Introsort();
    void setArray();
    void setArray(T* arr);
    void sort();
    void printArray();
    T &operator[](int i);
    T* getArray();
};

template<class T>
void Introsort<T>::swap(T &a, T &b) {
    T tmp;
    tmp = a; a = b; b = tmp;
}

template<class T>
int Introsort<T>::partition(int p, int r) {
    T x = arr[r];
    int i = p - 1;
    for(int j = p; j <= r - 1; j++) {
        if(arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return (i + 1);
}

template<class T>
void Introsort<T>::introsort(int p, int r, int depth) {
    if(p < r) {
        int q = partition(p, r);
        if (arrSize <= 1) {
            return;
        }
        if (depth == 0) {
            heapSort(arrSize);
        } else {
            introsort(p, q - 1, depth--);
            introsort(q + 1, r, depth--);
        }
    }
}

template<class T>
Introsort<T>::Introsort(int size) {
    arrSize = size;
    arr = new T[arrSize];
}

template<class T>
Introsort<T>::~Introsort() {
    delete[] arr;
}

template<class T>
void Introsort<T>::setArray() {
    for(int i = 0; i < arrSize; i++) {
        std::cout << "Enter the " << i + 1 << " element: "; std::cin >> arr[i];
    }
}

template<class T>
void Introsort<T>::setArray(T *arr) {
    for(int i = 0; i < arrSize; i++) {
        std::cout << "Enter the " << i + 1 << " element: "; std::cin >> arr[i];
    }
}

template<class T>
void Introsort<T>::sort() {
    int maxDepth = (int)(floor(log(arrSize)));
    introsort(0, arrSize - 1, maxDepth);
}

template<class T>
void Introsort<T>::printArray() {
    for(int i = 0; i < arrSize; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template<class T>
T *Introsort<T>::getArray() {
    return arr;
}

template<class T>
T &Introsort<T>::operator[](int i) {
    if(i < 0) {
        std::cout << "Array index error\n";
        exit(1);
    } else if(i >= arr.size()) {
        arr.resize(i + 1);
    }
    return this->arr[i];
}

template<class T>
void Introsort<T>::heapify(int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(n, largest);
    }
}

template<class T>
void Introsort<T>::heapSort(int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(i, 0);
    }
}

template <>
Introsort<char *>::Introsort(int size) {
    arrSize = size;
    arr = new char*[arrSize];
    for(int i = 0; i < arrSize; i++) {
        arr[i] = new char[50];
    }
}

template <>
void Introsort<char *>::setArray() {
    for(int i = 0; i < arrSize; i++) {
        std::cout << "Enter the " << i + 1 << " element: ";
        std::cin.getline(arr[i], 50);
    }
}

template <>
void Introsort<Date>::printArray() {
    for(int i = 0; i < arrSize; i++) {
        arr[i].printDate();
        std::cout << ' ';
    }
    std::cout << '\n';

}

template <>
void Introsort<Date>::setArray() {
    for(int i = 0; i < arrSize; i++) {
        int d, m, y;
        std::cout << "Enter the date of " << i + 1 << " element: "; std::cin >> d >> m >> y;
        arr[i] = Date(d, m, y);
    }
}

template <>
void Introsort<octal_number>::setArray() {
    for(int i = 0; i < arrSize; i++) {
        int intNumber;
        std::cout << "Enter the " << i + 1 << " int to octal number: "; std::cin >> intNumber;
        arr[i].setIntNumber(intNumber);
    }
}

template <>
void Introsort<octal_number>::printArray() {
    for(int i = 0; i < arrSize; i++) {
        std::cout << arr[i].getOctNumber() << ' ';
    }
    std::cout << std::endl;
}




#endif //INTROSORT_INTROSPECTION_SORT_H
