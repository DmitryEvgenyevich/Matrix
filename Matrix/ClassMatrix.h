#pragma once
#include <iostream>

template<class T>
class Matrix
{
private:
	int _size;
	T** _arr;
	void _clearArr();
	void _newMemory();
	bool _comparisonFunction(const Matrix<T>& matrix, bool(*fun)(const int, const int)) const;
	

public:
	explicit Matrix(int size = 0);
	Matrix(const Matrix<T>& temp);
	Matrix(Matrix<T>&& temp);
	~Matrix();

	// Получить размер массива
	int getSize() const;
	// Сумма всего масива
	T sumArr() const;
	// Вывести весь массив
	void printAllArr() const;
	// Присвоить значение value по индексам index и index2
	void setValueByIndex(int index, int index2, T value);
	// Получить значение value по индексам index и index2
	T getValueByIndex(int index, int index2) const;
	// Заполнение массива рандомными значениями с пределами 
	//void fill(T min, T max);
	// Добовляет к каждому элементу массива 1 (Префиксный)
	Matrix<T>& operator++();
	// Добовляет к каждому элементу массива 1 (Постфиксный)
	Matrix<T> operator++(int);
	// Отнимает к каждому элементу массива 1 (Префиксный)
	Matrix<T>& operator--();
	// Отнимает к каждому элементу массива 1 (Постфиксный)
	Matrix<T> operator--(int);
	// Оператор присваивания копированием
	Matrix<T>& operator=(const Matrix<T>& matrix);
	// Оператор присваивания переносом
	Matrix<T>& operator=(Matrix<T>&& matrix);
	// Оператор сравнения равно
	bool operator==(const Matrix<T>& matrix) const;
	// Оператор сравнения не равно
	bool operator!=(const Matrix<T>& matrix) const;
	// Оператор сравнения меньше
	bool operator<(const Matrix<T>& matrix) const;
	// Оператор сравнения больше
	bool operator>(const Matrix<T>& matrix) const;
	// Оператор сравнения меньше или равно
	bool operator<=(const Matrix<T>& matrix) const;
	// Оператор сравнения больше или равно
	bool operator>=(const Matrix<T>& matrix) const;
	// Запрос одномерного массива из дувухмерного
	T*& operator[](const int index1) const;
	// Запрос значения по индексам
	T operator()(const int index1, const int index2) const;
};

template<class T>
bool _isMoreMatrices(const T a, const T b);

template<class T>
bool _isLessMatrices(const T a, const T b);

template<class T>
bool _isMoreOrEqualMatrices(const T a, const T b);

template<class T>
bool _isLessOrEqualMatrices(const T a, const T b);