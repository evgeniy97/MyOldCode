// Decorator.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "cmath"
//3.  Шаблон Декоратор(Decorator)
//a.Реализовать калькулятор, который выполняет простые математические операции.
//Использовать шаблон Декоратор для подключения новых математических функций(степень, корень, sin, cos).

// Вариант 2
using namespace std;

class base;
class calculator;
class SIN;

class base
{
protected:
	double I;
public:
	base() {};
	double gv() { return I; };
	void ch(double i) { I = i; }
	virtual void func() = 0;
};

class calculator : public base
{
public:
	calculator(double i) { I = i; cout << "NUMBER|" << I << endl; }
	calculator(base *w) : calculator(w->gv()) {};
	void func()
	{
		cout << "NUMBER|" << I << endl;
	}
	calculator * plus(double J) {
		cout << " PLUS " << J << "|" << I << endl;
		I += J;
		return this;
	}
	calculator * minus(double J) {
		cout << " MINUS " << J << "|" << I << endl;
		I -= J;
		return this;
	}
	calculator * div(double J) {
		cout << " DIVISION " << J << "|" << I << endl;
		I /= J;
		return this;
	}
	calculator * mpl(double J) {
		cout << " MPL " << J << "|" << I << endl;
		I *= J;
		return this;
	}
};
class decorator : public base
{
	base* b;
public:
	decorator(base *w) {
		b = w;
	}
	void func()
	{
		b->func();
	}
};

class SIN : public decorator
{
	double i;
public:
	SIN(base *w) : decorator(w) { I = (*w).gv(); i = I; ch(sin(I)); };
	void func()
	{
		decorator::func();
		cout << " SIN(" << i << ")|" << I << endl;
	}
};
class COS : public decorator
{
	double i;
public:
	COS(base *w) : decorator(w) { I = (*w).gv(); i = I; ch(cos(I)); };
	void func()
	{
		decorator::func();
		cout << " COS(" << i << ")|" << I << endl;
	}
};
class POW : public decorator
{
	double i;
public:
	POW(base *w, double j) : decorator(w) { I = (*w).gv(); i = j; ch(pow(I, i)); };
	void func()
	{
		decorator::func();
		cout << " POW(" << i << ")|" << I << endl;
	}
};
class SQRT : public decorator
{
	double i;
public:
	SQRT(base *w) : decorator(w) { I = (*w).gv(); i = I; ch(sqrt(I)); };
	void func()
	{
		decorator::func();
		cout << " SQRT(" << i << ")|" << I << endl;
	}
};
int main() {
	// перед calculator не нужно new
	base* Base = new SQRT(new POW(calculator(new SIN( new COS(calculator(calculator(5).plus(3)).div(2)))).plus(10),2));
	Base->func();
}