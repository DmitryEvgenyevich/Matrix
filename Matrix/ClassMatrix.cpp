#include "ClassMatrix.h"

//------------ private ----------------
void Matrix::_clearArr()
{
	for (int i{}; i < this->_size; ++i)
		delete[] this->_arr[i];
	delete[] this->_arr;
}

void Matrix::_newMemory()
{
	this->_arr = new int* [this->_size];
	for (int i{}; i < this->_size; ++i)
		this->_arr[i] = new int[this->_size] {};
}

bool Matrix::_comparisonFunction(const Matrix& matrix, bool(*fun)(const int, const int)) const
{
	if (*this == matrix)
		return 1;

	for (int i{}; i < this->_size; ++i)
	{
		for (int j{}; j < this->_size; ++j)
			if (fun(matrix.sumArr(), this->sumArr()))
				return 0;
	}

	return 1;
}

//------------ public -----------------
Matrix::Matrix(int size) :
	_size{ size }
{
	_newMemory();
}

Matrix::Matrix(const Matrix& temp) :
	_size{ temp._size }
{
	this->_arr = new int* [this->_size];
	for (int i{}; i < this->_size; ++i)
	{
		this->_arr[i] = new int[_size];
		for (int j{}; j < this->_size; ++j)
			this->_arr[i][j] = temp._arr[i][j];
	}		
}

Matrix::Matrix(Matrix&& temp) :
	_size{ temp._size }
{
	this->_arr = temp._arr;
	
	temp._arr = nullptr;
}

Matrix::~Matrix()
{
	if (this->_arr != nullptr)
		this->_clearArr();
}

int Matrix::getSize() const
{
	return this->_size;
}

int Matrix::sumArr() const
{
	int temp{};
	for (int i{}; i < this->_size; ++i)
		for (int j{}; j < this->_size; ++j)
			temp += this->_arr[i][j];

	return temp;
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

Matrix& Matrix::operator++()
{
	for (int i{}; i < this->_size; ++i)
	{
		for (int j{}; j < this->_size; ++j)
		{
			++this->_arr[i][j];
		}
	}
	return *this;
}

Matrix Matrix::operator++(int)
{
	Matrix temp = *this;

	for (int i{}; i < this->_size; ++i)
	{
		for (int j{}; j < this->_size; ++j)
		{
			++this->_arr[i][j];
		}
	}
	return temp;
}

Matrix& Matrix::operator--()
{
	for (int i{}; i < this->_size; ++i)
	{
		for (int j{}; j < this->_size; ++j)
		{
			--this->_arr[i][j];
		}
	}

	return *this;
}

Matrix Matrix::operator--(int)
{
	Matrix temp = *this;

	for (int i{}; i < this->_size; ++i)
	{
		for (int j{}; j < this->_size; ++j)
		{
			--this->_arr[i][j];
		}
	}
	return temp;
}

Matrix& Matrix::operator=(const Matrix& matrix)
{
	this->_size = matrix._size;

	this->_clearArr();
	
	this->_newMemory();

	for (int i{}; i < this->_size; ++i)
	{
		for (int j{}; j < this->_size; ++j)
			this->_arr[i][j] = matrix._arr[i][j];
	}
}

Matrix& Matrix::operator=(Matrix&& matrix)
{
	this->_size = matrix._size;

	delete[] this->_arr;

	this->_arr = matrix._arr;
	matrix._arr = nullptr;
	
	return *this;
}

bool Matrix::operator==(const Matrix& matrix) const
{
	if (*this == matrix)
		return 1;

	for (int i{}; i < this->_size; ++i)
	{
		for (int j{}; j < this->_size; ++j)
			if (this->_arr[i][j] != matrix._arr[i][j])
				return 0;
	}

	return 1;
}

bool Matrix::operator!=(const Matrix& matrix) const
{
	return !(*this == matrix);
}

bool Matrix::operator<(const Matrix& matrix) const
{
	return this->_comparisonFunction(matrix, _isLessMatrices);
}

bool Matrix::operator>(const Matrix& matrix) const
{
	return this->_comparisonFunction(matrix, _isMoreMatrices);
}

bool Matrix::operator<=(const Matrix& matrix) const
{
	return this->_comparisonFunction(matrix, _isLessOrEqualMatrices);
}

bool Matrix::operator>=(const Matrix& matrix) const
{
	return this->_comparisonFunction(matrix, _isMoreOrEqualMatrices);
}

int*& Matrix::operator[](const int index1) const
{
	return this->_arr[index1];
}

int Matrix::operator()(const int index1, const int index2) const
{
	return this->_arr[index1][index2];
}

//------------ add fun ----------------

bool _isLessMatrices(const int a, const int b)
{
	return (a < b);
}

bool _isMoreMatrices(const int a, const int b)
{
	return (a > b);
}

bool _isLessOrEqualMatrices(const int a, const int b)
{
	return (a <= b);
}

bool _isMoreOrEqualMatrices(const int a, const int b)
{
	return (a >= b);
}
