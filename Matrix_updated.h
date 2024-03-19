#pragma once
#ifndef MATRIXUPDATED_H
#define MATRIXUPDATED_H
#include <random>
#include <ctime>
#include <iostream>
#include <iomanip>

template <typename T>

class Matrix {
private:
    unsigned int m; // Строки
    unsigned int n; // Столбцы 
    T** data;
    class Matrix* next;

public:

    Matrix(unsigned int m, unsigned int n) : m(m), n(n) {
        data = new T* [m];
        for (unsigned int i = 0; i < m; ++i) {
            data[i] = new int[n];
        }
    }

    ~Matrix() {
        for (unsigned int i = 0; i < n; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix);

    int*& operator[](unsigned int index) { // Возвращая ссылку на указатель, можем обращаться как matrix[][]
        return data[index];
    }

    void fillRandom() {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] = static_cast<T>(std::rand() % 10);
            }
        }
    }

    void fillZeros() {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] = static_cast<T>(0);
            }
        }
    }

    Matrix& operator+=(const Matrix& other) {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix& operator-=(const Matrix& other) {
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                data[i][j] -= other.data[i][j];
            }
        }
        return *this;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result(m, n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(m, other.n);
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < other.n; ++j) {
                result.data[i][j] = static_cast<T>(0);
                for (unsigned int k = 0; k < n; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    bool operator==(const Matrix& other) const {
        if (m != other.m || n != other.n) {
            return false;
        }
        for (unsigned int i = 0; i < m; ++i) {
            for (unsigned int j = 0; j < n; ++j) {
                if (data[i][j] != other.data[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Matrix& other) const {
        return !(*this == other);
    }
    
    std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
        for (unsigned int i = 0; i < matrix.m; ++i) {
            os << " " << std::endl;
            for (unsigned int j = 0; j < matrix.n; ++j) {
                os << std::setw(3) << matrix.data[i][j] << " | ";
            }
            os << '\n';
        }
        return os;
    }
};


#endif