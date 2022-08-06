#pragma once
#include <iostream>

class Matrix
{
private:
	int _size;
	int** _arr;

public:
	Matrix(int size = 0);
	Matrix(const Matrix& temp);
	~Matrix();
	int getSize() const;
	void printAllArr() const;
	void setValueByIndex(int index, int index2, int value);
	int getValueByIndex(int index, int index2) const;
	void fill(int min = 0, int max = 10);

};
