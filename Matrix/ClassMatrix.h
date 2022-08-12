#pragma once
#include <iostream>

class Matrix
{
private:
	int _size;
	int** _arr;

public:
	explicit Matrix(int size = 0);
	Matrix(const Matrix& temp);
	~Matrix();

	// Получить размер массива
	int getSize() const;
	// Вывести весь массив
	void printAllArr() const;
	// Присвоить значение value по индексам index и index2
	void setValueByIndex(int index, int index2, int value);
	// Получить значение value по индексам index и index2
	int getValueByIndex(int index, int index2) const;
	// Заполнение массива рандомными значениями с пределами 
	void fill(int min = 0, int max = 10);
	// Добовляет к каждому элементу массива 1 (Префиксный)
	Matrix& operator++();
	// Добовляет к каждому элементу массива 1 (Постфиксный)
	Matrix operator++(int);
	// Отнимает к каждому элементу массива 1 (Префиксный)
	Matrix& operator--();
	// Отнимает к каждому элементу массива 1 (Постфиксный)
	Matrix operator--(int);

};
