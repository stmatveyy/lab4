#include "MaxIndex.h"
#include "Vector.h"
#include <iostream>

int main() {
    int intArr[] = { 1, 3, 2 };
    int intMaxIndex = findSecondMaxIndex(intArr, 5);
    std::cout << "Индекс второго максимума в массиве int: " << intMaxIndex << std::endl;

    float floatArr[] = { 1.5, 3.7, 2.1, 5.2, 4.8 };
    int floatMaxIndex = findSecondMaxIndex(floatArr, 5);
    std::cout << "Индекс второго максимума в массиве float: " << floatMaxIndex << std::endl;

    char charArr[] = { 'a', 'c', 'b', 'e', 'd' };
    int charMaxIndex = findSecondMaxIndex(charArr, 5);
    std::cout << "Индекс второго максимума в массиве char: " << charMaxIndex << std::endl;

    double doubleArr[] = { 1.5, 3.7, 2.1, 5.2, 4.8 };
    int doubleMaxIndex = findSecondMaxIndex(doubleArr, 5);
    std::cout << "Индекс второго максимума в массиве double: " << doubleMaxIndex << std::endl;


   
    return 0;
}