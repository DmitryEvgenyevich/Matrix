#include "ClassMatrix.h"

//------------ private ----------------
template<class T>
void Matrix<T>::_clearArr()
{
	for (int i{}; i < this->_size; ++i)
		delete[] this->_arr[i];
	delete[] this->_arr;
}

template<class T>
void Matrix<T>::_newMemory()
{
	this->_arr = new T* [this->_size];
	for (int i{}; i < this->_size; ++i)
		this->_arr[i] = new T[this->_size] {};
}

template<class T>
bool Matrix<T>::_comparisonFunction(const Matrix<T>& matrix, bool(*fun)(const int, const int)) const
{
	if (this == &matrix)
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
template<class T>
Matrix<T>::Matrix(int size) :
	_size{ size }
{
	_newMemory();
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& temp) :
	_size{ temp._size }
{
	this->_arr = new T* [this->_size];
	for (int i{}; i < this->_size; ++i)
	{
		this->_arr[i] = new T[_size];
		for (int j{}; j < this->_size; ++j)
			this->_arr[i][j] = temp._arr[i][j];
	}		
}

template<class T>
Matrix<T>::Matrix(Matrix<T>&& temp) :
	_size{ temp._size }
{
	this->_arr = temp._arr;
	
	temp._arr = nullptr;
}

template<class T>
Matrix<T>::~Matrix()
{
	if (this->_arr != nullptr)
		this->_clearArr();
}

template<class T>
int Matrix<T>::getSize() const
{
	return this->_size;
}

template<class T>
T Matrix<T>::sumArr() const
{
	int temp{};
	for (int i{}; i < this->_size; ++i)
		for (int j{}; j < this->_size; ++j)
			temp += this->_arr[i][j];

	return temp;
}

template<class T>
void Matrix<T>::printAllArr() const
{
	for (int i{}; i < this->_size; ++i)
	{
		for (int j{}; j < this->_size; ++j)
			std::cout << _arr[i][j] << '\t';
		std::cout << '\n';
	}
	std::cout << "\n";
}

template<class T>
void Matrix<T>::setValueByIndex(int index, int index2, T value)
{
	this->_arr[index][index2] = value;
}

template<class T>
T Matrix<T>::getValueByIndex(int index, int index2) const
{
	return this->_arr[index][index2];
}

//template<class T>
//void Matrix<T>::fill(T min, T max)
//{
//	for (int i{}; i < this->_size; ++i)
//		for (int j{}; j < this->_size; ++j)
//			this->_arr[i][j] = min + rand() % (max - min + 1);
//}

template<class T>
Matrix<T>& Matrix<T>::operator++()
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

template<class T>
Matrix<T> Matrix<T>::operator++(int)
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

template<class T>
Matrix<T>& Matrix<T>::operator--()
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

template<class T>
Matrix<T> Matrix<T>::operator--(int)
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

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& matrix)
{
	this->_clearArr();
	this->_size = matrix._size;
	this->_newMemory();

	for (int i{}; i < this->_size; ++i)
	{
		for (int j{}; j < this->_size; ++j)
			this->_arr[i][j] = matrix._arr[i][j];
	}

	return *this;
}

template<class T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& matrix)
{
	this->_size = matrix._size;

	delete[] this->_arr;

	this->_arr = matrix._arr;
	matrix._arr = nullptr;
	
	return *this;
}

template<class T>
bool Matrix<T>::operator==(const Matrix<T>& matrix) const
{
	if (this == &matrix)
		return 1;

	for (int i{}; i < this->_size; ++i)
	{
		for (int j{}; j < this->_size; ++j)
			if (this->_arr[i][j] != matrix._arr[i][j])
				return 0;
	}

	return 1;
}

template<class T>
bool Matrix<T>::operator!=(const Matrix<T>& matrix) const
{
	return !(*this == matrix);
}

template<class T>
bool Matrix<T>::operator<(const Matrix<T>& matrix) const
{
	return this->_comparisonFunction(matrix, _isLessMatrices);
}

template<class T>
bool Matrix<T>::operator>(const Matrix<T>& matrix) const
{
	return this->_comparisonFunction(matrix, _isMoreMatrices);
}

template<class T>
bool Matrix<T>::operator<=(const Matrix<T>& matrix) const
{
	return this->_comparisonFunction(matrix, _isLessOrEqualMatrices);
}

template<class T>
bool Matrix<T>::operator>=(const Matrix<T>& matrix) const
{
	return this->_comparisonFunction(matrix, _isMoreOrEqualMatrices);
}

template<class T>
T*& Matrix<T>::operator[](const int index1) const
{
	return this->_arr[index1];
}

template<class T>
T Matrix<T>::operator()(const int index1, const int index2) const
{
	return this->_arr[index1][index2];
}

//------------ add fun ----------------

template<class T>
bool _isLessMatrices(const T a, const T b)
{
	return (a < b);
}

template<class T>
bool _isMoreMatrices(const T a, const T b)
{
	return (a > b);
}

template<class T>
bool _isLessOrEqualMatrices(const T a, const T b)
{
	return (a <= b);
}

template<class T>
bool _isMoreOrEqualMatrices(const T a, const T b)
{
	return (a >= b);
}
