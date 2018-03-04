// KP_do_16.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "vector"

using namespace std;

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
	Matrix transposition();
	void print();
	Matrix operator+(const Matrix & mat) const;
	Matrix operator*(const double & number) const;
	Matrix operator*(const Matrix& mat) const;

	~Matrix();
};


int main()
{
	Matrix mat(2, 3, {1,2,3,6,3,0});
	Matrix mat_(3, 2, { 1,0,0,4,7,0});
	(mat*mat_).transposition().print();
    return 0;
}

Matrix::Matrix(unsigned int rows, unsigned int columns) :
	Rows(rows),
	Columns(columns) {

}

Matrix::Matrix(unsigned int rows, unsigned int columns, vector <double> elements) :
	Rows(rows),
	Columns(columns),
	Elements(elements)
{

}
double Matrix::get(unsigned int i, unsigned int j) const
{
	return Elements[i*Columns + j];
}

void Matrix::set(unsigned int i, unsigned int j, double val)
{
	Elements[i*Columns + j] = val;
}

void Matrix::print()
{
	for (unsigned int i = 0; i < Rows; i++)
	{
		for (unsigned int j = 0; j < Columns; j++)
		{
			cout << Elements[i*(Columns) + j] << " ";
		}
		cout << endl;
	}
}

Matrix Matrix::operator+(const Matrix & mat) const
{
	// Проверка, одинакова ли размерность матриц
	if ((this->Rows != mat.Rows) && (this->Columns != mat.Columns)) throw - 1;
	vector <double> elements;
	for (unsigned int i = 0; i < Rows*Columns; i++)
	{
		elements.push_back(this->Elements[i] + mat.Elements[i]);
	}
	return Matrix(Rows, Columns, elements);
}

Matrix Matrix::operator*(const double & number) const
{
	vector <double> elements;
	for (unsigned int i = 0; i < Rows*Columns; i++)
	{
		elements.push_back(this->Elements[i] * number);
	}
	return Matrix(Rows, Columns, elements);
}

Matrix Matrix::operator*(const Matrix& mat) const {
	if (this->Columns != mat.Rows) throw "different sizes of matrices while multiplication";

	vector <double> new_elements;
	for (size_t i = 0; i < this->Rows * mat.Columns; i++) new_elements.push_back(0);

	for (size_t i = 0; i < this->Rows; i++)
	{
		for (size_t j = 0; j < mat.Columns; j++)
		{
			for (size_t r = 0; r < this->Columns; r++)
			{
			new_elements[i*mat.Columns + j] += this->get(i, r) *mat.Elements[r*mat.Columns + j];
			}
		}
	}
	return Matrix(this->Rows, mat.Columns, new_elements);
};

Matrix Matrix::transposition() {
	vector <double> new_elements;

	for (size_t i = 0; i < (Columns *Rows); i++) new_elements.push_back(0);

	for (size_t i = 0; i < this->Rows; i++)
	{
		for (size_t j = 0; j < this->Columns; j++)
		{
			new_elements[j*this->Rows + i] = this->Elements[i*this->Columns + j];
		}
	}
	return Matrix(this->Columns, this->Rows, new_elements);;
};


Matrix::~Matrix()
{
}