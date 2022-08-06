#include "ClassMatrix.h"

Matrix::Matrix(int size) :
	_size{ size }
{
	_arr = new int* [_size];
	for (int i{}; i < _size; ++i)
		_arr[i] = new int[_size];
}

Matrix::Matrix(const Matrix& temp):
	_size { temp._size },
	_arr{ temp._arr }
{}

Matrix::~Matrix()
{
	for (int i = 0; i < _size; i++)
		delete[] _arr[i];
	delete[] _arr;
}

int Matrix::getSize() const
{
	return this->_size;
}

void Matrix::printAllArr() const
{
	for (int i{}; i < this->_size; ++i)
	{
		for (int j{}; j < this->_size; ++j)
			std::cout << _arr[i][j] << '\t';
		std::cout << '\n';
	}
	std::cout << "\n";
}

void Matrix::setValueByIndex(int index, int index2, int value)
{
	this->_arr[index][index2] = value;
}

int Matrix::getValueByIndex(int index, int index2) const
{
	return this->_arr[index][index2];
}

void Matrix::fill(int min, int max)
{
	for (int i{}; i < this->_size; ++i)
		for (int j{}; j < this->_size; ++j)
			this->_arr[i][j] = min + rand() % (max - min + 1);
}
