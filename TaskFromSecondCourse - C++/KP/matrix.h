#pragma once

#ifndef __matrix_H__
#define __matrix_H__

#include "stdafx.h"
#include "matrix.cpp"
#include "vector"
#include "iostream"

using namespace std;
//1	get(unsigned int i, unsigned int j) - получить элемент матрицы с индексами[i, j]
//2	set(unsigned int i, unsigned int j, double val) - записать значение val в элемент матрицы с индексами[i, j]
//3	print - вывод матрицы в стандартный поток вывода std::cout.
//4	matsum - матричное cсуммирование.При Суммировании матриц A, B размерами(N, K) и(N, K) метод создает(и возвращает) новую матрицу C(N, K).
//5	matmultc – умножение матрицы на константу.При умножении матрицы A размером(N, K) метод создает новую матрицу B.


class Matrix {
protected:
	// Количество строк
	unsigned int Rows;
	//Количесвто столбцов
	unsigned int Columns;
	// Используем одномерный массив, строки друг за другом, доступ к элементу i,j получаем с помощью i*Rows+j
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