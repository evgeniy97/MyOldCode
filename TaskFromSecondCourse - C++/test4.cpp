// test4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <utility> // для std::move и std::forward
#include "iostream"
#include "string"
#include <typeinfo>

//Напишите функцию apply, которая принимает некоторую функцию / функциональный объект,
//а так же аргументы для вызова этого объекта,
//и вызывает его, используя perfect forwarding.

//Примечание: гарантируется, что количество аргументов, 
//переданных в apply, в совпадает с количеством аргументов у функции / функционального объекта.
//При этом у функции может быть произвольное число аргументов.

//Hint : ﻿в данном задании нужно использовать новый синтаксис определения функций.



// реализация функции apply
//template <class A , typename... Args> auto apply(A fun, Args..argv = [])
//{
//	return fun(std::forward<Args>(argv));
//}

//template <class A , typename... Args> 
//auto apply(A fun = typename typeid(fun).name() , Args..argv = []) -> decltype(fun(std::forward<Args>(argv)))
//{
//	return fun(std::forward<Args>(argv));
//}

template <class A, typename... Args>
auto apply(A fun , Args&&...  argv) -> decltype( fun(argv...) )
{
	return fun(std::forward<Args>(argv)...);
	//return fun(argv...);
}



int main()
{
	auto fun = [](std::string a, std::string const& b) { return a += b; };
	auto f = [](std::string str) {std::cout << str; };
	auto f_ = []() {std::cout << "Hello\n"; };

	std::string s("world!");

	apply(f,"Hi\n");
	apply(f_);

	// s передаётся по lvalue ссылке,
	// а временный объект по rvalue ссылке


	s = apply(fun, std::string("Hello, "), s);
	std::cout << s << std::endl;
	int i;
	std::cin >> i;
    return 0;
}

