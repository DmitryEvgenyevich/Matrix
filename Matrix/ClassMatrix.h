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

	// �������� ������ �������
	int getSize() const;
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

};
