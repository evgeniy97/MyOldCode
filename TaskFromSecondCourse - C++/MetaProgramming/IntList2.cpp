// IntList2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

// определяем список
template <int  ...>
struct IntList {};

// специализация для пустого списка
template <> struct IntList<> {
};


template <int first, int... other>
struct IntList<first, other...>
{
	static const int Head = first;
	using Tail = IntList<other...>;
};

template<int H, typename TL = IntList<> >
struct Generate;

// Начало рекурсии
template<int H>
struct Generate<H>
{
	using T = Generate<H - 1, IntList<H - 1>>;
	using type = T::type;
	//using type = IntList<Generate<H-1>,H-1>
};
// Шаг рекурсии
// #1
template<int H, int... Types>
struct Generate<H, IntList<Types...> >
{
	using T = Generate<H - 1, IntList<H - 1, Types...>>;
	using type = T::type;
};
// Конец рекурссии
template<int... Types>
struct Generate<1, IntList<Types...> >
{
	using type = IntList<0, Types...>;
};
// Для случая Generate<1>
template<>
struct Generate<1>
{
	using type = IntList<0>;
};

int main()
{
	using L3 = Generate<5>::type;
	return 0;
}

