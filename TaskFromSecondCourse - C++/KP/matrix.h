#pragma once

#ifndef __matrix_H__
#define __matrix_H__

#include "stdafx.h"
#include "matrix.cpp"
#include "vector"
#include "iostream"

using namespace std;
//1	get(unsigned int i, unsigned int j) - �������� ������� ������� � ���������[i, j]
//2	set(unsigned int i, unsigned int j, double val) - �������� �������� val � ������� ������� � ���������[i, j]
//3	print - ����� ������� � ����������� ����� ������ std::cout.
//4	matsum - ��������� c������������.��� ������������ ������ A, B ���������(N, K) �(N, K) ����� �������(� ����������) ����� ������� C(N, K).
//5	matmultc � ��������� ������� �� ���������.��� ��������� ������� A ��������(N, K) ����� ������� ����� ������� B.


class Matrix {
protected:
	// ���������� �����
	unsigned int Rows;
	//���������� ��������
	unsigned int Columns;
	// ���������� ���������� ������, ������ ���� �� ������, ������ � �������� i,j �������� � ������� i*Rows+j
	vector <double> Elements;
public:
	Matrix(unsigned int rows, unsigned int columns);
	Matrix(unsigned int rows, unsigned int columns, vector <double> elements);
	double get(unsigned int i, unsigned int j) const;
	void set(unsigned int i, unsigned int j, double val);
	void print();
	Matrix operator+(const Matrix & mat) const;
	Matrix operator*(const double & number) const;

	~Matrix();
};

#endif // __matrix_H__