#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include <cassert>
#include <iostream>

template <typename T>
class Vector {
private:
	unsigned int m;
	T* data;

public:
	Vector(unsigned int m) : m(m) {
		data = new T[m];
		for (unsigned int i = 0; i < m; ++i) {
			data[i] = static_cast<T>(0);
		}
	}

	~Vector() {
		delete[] data;
	}

	T operator*(Vector<T>& other) {
		assert(m == other.m);
		T result = static_cast<T>(0);

		for (unsigned int i = 0; i < m; ++i) {
			result += data[i] * other.data[i];
		}
		return result;
	}

	T* operator[](size_t index) {
		return data[index];
	}

	friend std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
		for (unsigned int i = 0; i < vec.m; ++i) {
			os << vec.data[i] << ' ';
		}
		return os;
	}
	
	Vector<T> vec_multiplication(Vector<T>& other) {
		assert(m == other.m && m == 3);
		Vector<T> result(m);

		result[0] = data[1] * other.data[2] - data[2] * other.data[1];
		result[1] = data[2] * other.data[0] - data[0] * other.data[2];
		result[2] = data[0] * other.data[1] - data[1] * other.data[0];

		return result;
	}
};
	
	


#endif