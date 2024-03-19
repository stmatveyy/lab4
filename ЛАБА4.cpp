#include "MaxIndex.h"
#include "Vector.h"
#include <iostream>
#include "Matrix_updated.h"

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

    Matrix<int> mat_int(3, 3);
    mat_int.fillRandom();
    std::cout << "Матрица int: " << mat_int << std::endl;
   
    Matrix<float> mat_float(3, 3);
    mat_float.fillRandom();
    std::cout << "Матрица float: " << mat_float << std::endl;

    Matrix<double> mat_double(3, 3);
    mat_double.fillRandom();
    std::cout << "Матрица double: " << mat_double << std::endl;

    Matrix<float> mat_float2(3, 3);
    mat_float2.fillRandom();
    std::cout << "Сумма матриц float: " << mat_float + mat_float2 << std::endl;


    Vector<int> vec_int1(3);
    vec_int1[0] = 3;
    vec_int1[1] = 3;
    vec_int1[2] = 3;

    Vector<int> vec_int2(3);
    vec_int2[0] = 5;
    vec_int2[1] = 5;
    vec_int2[2] = 5;

    std::cout << "Скалярное произведение int-векторов: " << vec_int1 * vec_int2 << std::endl;
    std::cout << "Векторное произведение int-векторов: " << vec_int1.vec_multiplication(vec_int2) << "\n" << std::endl;

    Vector<float> vec_float1(3);
    vec_float1[0] = 3.;
    vec_float1[1] = 3.;
    vec_float1[2] = 3.;

    Vector<float> vec_float2(3);
    vec_float2[0] = 5.;
    vec_float2[1] = 5.;
    vec_float2[2] = 5.;

    std::cout << "Скалярное произведение float-векторов: " << vec_float1 * vec_float2 << std::endl;
    std::cout << "Векторное произведение float-векторов: " << vec_float1.vec_multiplication(vec_float2) << "\n" << std::endl;

    Vector<double> vec_double1(3);
    vec_double1[0] = 3.;
    vec_double1[1] = 3.;
    vec_double1[2] = 3.;

    Vector<double> vec_double2(3);
    vec_double2[0] = 5.;
    vec_double2[1] = 5.;
    vec_double2[2] = 5.;

    std::cout << "Скалярное произведение double-векторов: " << vec_double1 * vec_double2 << std::endl;
    std::cout << "Векторное произведение double-векторов: " << vec_double1.vec_multiplication(vec_double2) << std::endl;
    return 0;
}