// Poem-.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

template <class Type> void sort_bubble(Type a[], int max);
template <class Type> void sort_choose(Type a[], int max);
template <class Type> void sort_shell(Type a[], int max);
template <class Type> void sort_hoare(Type a[], int l, int r);
template <class Type> void sort_quick(Type a[], int l, int r);

class Poem
{
public:
	string st;

	Poem() : st("My") {}
	Poem(string new_st) : st(new_st) {}

	void print() {
		cout << st << endl;
	}

	Poem& operator=(const Poem &p) {    // Copy-operator
		st = p.st;

		return *this;
	}

	int w() const {
		return st.length();
	}

	bool operator==(const Poem &p) const {

		return ((this->w()) == (p.w()));
	}

	bool operator!=(const Poem &p) const {
		return !operator==(p);
	}

	bool operator>=(const Poem &p) const {
		return (this->w() >= p.w());
	}

	bool operator>(const Poem &p) const {
		return (this->w() > p.w());
	}

	bool operator<(const Poem &p) const { return !operator>=(p); }
	bool operator<=(const Poem &p) const { return !operator>(p); }

	~Poem() {}

	friend ostream& operator << (ostream &out, Poem &p); // перегрузка оператора <<
	friend istream& operator >> (istream &in, Poem &p); // перегрузка оператора >>

};

ostream &operator<<(ostream &out, Poem &p)
{
	out << p.st << endl;

	return out;
}

istream &operator >> (istream &in, Poem &p)
{
	in >> p.st;

	return in;
}


int main()
{
	int n;
	ifstream in("in.txt");
	in >> n;
	Poem *deck;
	deck = new Poem[n];
	for (int i = 0; i < n; i++) {
		in >> deck[i];
	};
	//Сортировки
	//sort_bubble(deck, n); // +
	sort_choose(deck, n); // +
						  //sort_shell(deck, n);// +
						  //sort_hoare(deck, 0, n-1); // +
						  //sort_quick(deck, 0, n - 1); // +

						  // Выывод
	ofstream out("out.txt");
	//out << n << endl;
	for (int i = 0; i < n; i++) out << deck[i];
	out.close();

    return 0;
}

template <class Type> void sort_bubble(Type a[], int max)      // пузырьковая сортировка
{
	for (int i = 0; i < max; i++)
		for (int j = max - 1; j > i; j--)
			if (/*less(a[j], a[j - 1])*/ a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}

template <class Type> void sort_choose(Type a[], int max)      // сортировка выбором методом вставки
{
	for (int i = 0; i<max; i++)
	{
		int k = i;
		for (int j = i + 1; j<max; j++)
			if (/*less(a[j], a[k])*/ a[j] < a[k])
				k = j;
		if (i != k)
			swap(a[i], a[k]);
	}
}

template <class Type> void sort_shell(Type a[], int max)               // сортировка Шелла
{
	for (int gap = max / 2; gap>0; gap /= 2)        // выбор интервала
		for (int i = gap; i<max; i++)               // проход массива
													// сравнение пар, отстоящих на gap друг от друга
			for (int j = i - gap; j >= 0 && a[j + gap] < a[j]  /*less(a[j + gap], a[j])*/; j -= gap)
				swap(a[j], a[j + gap]);
}

template <class Type> void sort_hoare(Type a[], int l, int r)   // сортировка Хоара
{
	int i = l, j = r, step = -1, condition = 1;
	if (l >= r) return;                   // сортировать нечего

	do {                         // сортируем с левой границы до правой
		if (condition == /*less(a[j], a[i])*/ (a[j] < a[i]))
		{
			swap(a[i], a[j]);             // перестановка чисел
			swap(i, j);                   // обмен местами индексов
			step = -step;                 // теперь - в другую сторону
			condition = !condition;       // обмен условия на противоположное
		}
		j += step;                        // передвинем индекс
	} while (j != i);                     // пока индексы не сойдутся
	sort_hoare(a, l, i - 1);               // левое подмножество
	sort_hoare(a, i + 1, r);               // правое
}

template <class Type> void sort_quick(Type a[], int l, int r) // QuickSort
{
	int i = l, j = r;
	Type x = a[(l + r) / 2];
	do {
		while (/*less(a[i], x)*/ a[i] < x) i++;
		while (/*less(x, a[j])*/ x < a[j]) j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		};
	} while (i<j);
	if (l<j) sort_quick(a, l, j);
	if (i<r) sort_quick(a, i, r);
}