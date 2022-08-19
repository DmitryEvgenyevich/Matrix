#pragma once
#include <iostream>

class Matrix
{
private:
	int _size;
	int** _arr;
	void _clearArr();
	void _newMemory();
	bool _comparisonFunction(const Matrix& matrix, bool(*fun)(const int, const int)) const;
	

public:
	explicit Matrix(int size = 0);
	Matrix(const Matrix& temp);
	Matrix(Matrix&& temp);
	~Matrix();

	// �������� ������ �������
	int getSize() const;
	// ����� ����� ������
	int sumArr() const;
	// ������� ���� ������
	void printAllArr() const;
	// ��������� �������� value �� �������� index � index2
	void setValueByIndex(int index, int index2, int value);
	// �������� �������� value �� �������� index � index2
	int getValueByIndex(int index, int index2) const;
	// ���������� ������� ���������� ���������� � ��������� 
	void fill(int min = 0, int max = 10);
	// ��������� � ������� �������� ������� 1 (����������)
	Matrix& operator++();
	// ��������� � ������� �������� ������� 1 (�����������)
	Matrix operator++(int);
	// �������� � ������� �������� ������� 1 (����������)
	Matrix& operator--();
	// �������� � ������� �������� ������� 1 (�����������)
	Matrix operator--(int);


	Matrix& operator=(const Matrix& matrix);
	Matrix& operator=(Matrix&& matrix);
	bool operator==(const Matrix& matrix) const;
	bool operator!=(const Matrix& matrix) const;
	bool operator<(const Matrix& matrix) const;
	bool operator>(const Matrix& matrix) const;
	bool operator<=(const Matrix& matrix) const;
	bool operator>=(const Matrix& matrix) const;
	int*& operator[](const int index1) const;
	int operator()(const int index1, const int index2) const;
};

bool _isMoreMatrices(const int a, const int b);
bool _isLessMatrices(const int a, const int b);
bool _isMoreOrEqualMatrices(const int a, const int b);
bool _isLessOrEqualMatrices(const int a, const int b);