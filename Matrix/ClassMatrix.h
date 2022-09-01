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

	// �������� ������ �������
	int getSize() const;
	// ����� ����� ������
	T sumArr() const;
	// ������� ���� ������
	void printAllArr() const;
	// ��������� �������� value �� �������� index � index2
	void setValueByIndex(int index, int index2, T value);
	// �������� �������� value �� �������� index � index2
	T getValueByIndex(int index, int index2) const;
	// ���������� ������� ���������� ���������� � ��������� 
	//void fill(T min, T max);
	// ��������� � ������� �������� ������� 1 (����������)
	Matrix<T>& operator++();
	// ��������� � ������� �������� ������� 1 (�����������)
	Matrix<T> operator++(int);
	// �������� � ������� �������� ������� 1 (����������)
	Matrix<T>& operator--();
	// �������� � ������� �������� ������� 1 (�����������)
	Matrix<T> operator--(int);
	// �������� ������������ ������������
	Matrix<T>& operator=(const Matrix<T>& matrix);
	// �������� ������������ ���������
	Matrix<T>& operator=(Matrix<T>&& matrix);
	// �������� ��������� �����
	bool operator==(const Matrix<T>& matrix) const;
	// �������� ��������� �� �����
	bool operator!=(const Matrix<T>& matrix) const;
	// �������� ��������� ������
	bool operator<(const Matrix<T>& matrix) const;
	// �������� ��������� ������
	bool operator>(const Matrix<T>& matrix) const;
	// �������� ��������� ������ ��� �����
	bool operator<=(const Matrix<T>& matrix) const;
	// �������� ��������� ������ ��� �����
	bool operator>=(const Matrix<T>& matrix) const;
	// ������ ����������� ������� �� ������������
	T*& operator[](const int index1) const;
	// ������ �������� �� ��������
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