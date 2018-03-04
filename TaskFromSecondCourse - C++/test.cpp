// test.cpp: определяет точку входа для консольного приложения.
//
//Напишите возвращающую bool шаблонную функцию compare,
//которая принимает две константные ссылки на объекты одного типа
//и указатель на константный метод этого типа без параметров,
//который в свою очередь возвращает значение какого - то второго типа.
//Функция должна сравнивать объекты по значениям, которые для них вернёт
//соответствующий метод, и возвращать true, если значение для первого объекта
//оказалось меньше, чем для второго.


#include "stdafx.h"
#include "iostream"
#include <string>

//using namespace std;

template class std::basic_string<char>;

//template<typename T, typename F> typedef F(T::*Method)() const;

template<typename T, typename F>
bool compare(T const & a, T const & b, F (T::*mptr)() const)
{
	return (a.*mptr)() < (b.*mptr)();
}

int main()
{
	std::string s1("Elf");
	std::string s2("Archer");

	// сравнение строк по длине
	bool r1 = compare(s1, s2, &std::string::size); // true
	bool r2 = compare(s1, s1, &std::string::size); // false

	std::cout << r1 << std::endl << r2 << std::endl;

	int i;
	std::cin >> i;
    return 0;
}

