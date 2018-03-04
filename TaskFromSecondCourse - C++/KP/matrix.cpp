#include "stdafx.h"
#include "matrix.h"

Matrix::Matrix(unsigned int rows, unsigned int columns):
	Rows(rows),
	Columns(columns){

}

Matrix::Matrix(unsigned int rows, unsigned int columns, vector <double> elements):
	Rows(rows),
	Columns(columns),
	Elements(elements)
	{

}
double Matrix::get(unsigned int i, unsigned int j) const
{
	return Elements[i*Rows+j];
}

void Matrix::set(unsigned int i, unsigned int j, double val)
{
	Elements[i*Rows + j] = val;
}

void Matrix::print()
{
	for (unsigned int i = 0; i < Rows; i++)
	{
		for (unsigned int j = 0; j < Columns; j++)
		{
			cout << Elements[i*Rows + j] << " ";
		}
		cout << endl;
	}
}

Matrix Matrix::operator+(const Matrix & mat) const
{
	// ѕроверка, одинакова ли размерность матриц
	if ((this->Rows != mat.Rows)&&(this->Columns != mat.Columns)) throw - 1;
	vector <double> elements;
	for (unsigned int i = 0; i < Rows*Columns; i++)
	{
		elements.push_back(this->Elements[i]+mat.Elements[i]);
	}
	return Matrix(Rows,Columns,elements);
}

Matrix Matrix::operator*(const double & number) const
{
	vector <double> elements;
	for (unsigned int i = 0; i < Rows*Columns; i++)
	{
		elements.push_back(this->Elements[i]*number);
	}
	return Matrix(Rows, Columns, elements);
}

Matrix::~Matrix()
{
}
