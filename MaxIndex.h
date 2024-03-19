#pragma once
#ifndef MAXINDEX_H
#define MAXINDEX_H
#include <iostream>


template <typename T>
int findSecondMaxIndex(T* arr, int size) {
    if (size < 2) {
        std::cerr << "list is too short\n";
        return -1;
    }

    int maxIndex = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

    int secondMaxIndex = (maxIndex == 0) ? 1 : 0;
    for (int i = 0; i < size; ++i) {
        if (i != maxIndex && arr[i] > arr[secondMaxIndex]) {
            secondMaxIndex = i;
        }
    }

    return secondMaxIndex;
}


#endif