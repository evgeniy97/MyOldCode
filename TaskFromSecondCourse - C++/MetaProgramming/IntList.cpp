// IntList.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>


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

// Длина списка

template<typename TL>
struct Length {
	static int const value = 1 + Length<typename TL::Tail>::value;
}; 
template<>struct
Length<IntList<>> 
{ static int const value = 0; };


// реализация метафункции IntCons

template<int H, typename TL>
struct IntCons; 

template< int H, int... Types>
struct IntCons< H, IntList<Types...>> 
{ 
	using type = IntList< H, Types...>;
};

template<typename TL1, typename TL2>
struct Concat; 

//template<typename... Ts1, typename... Ts2>
//struct Concat<IntList<Ts1...>, IntList<Ts2...>>
//{ using type = IntList<Ts1..., Ts2...>; };


template<int H, typename TL = IntList<> >
struct Generate;

// Начало рекурсии
template<int H>
struct Generate<H>
{
	using type = typename Generate<H - 1, IntList<H - 1>>::type;
};

// Шаг рекурсии
// #1
template<int H, int... Types>
struct Generate<H, IntList<Types...> >
{
	using type = typename Generate<H - 1, IntList<H - 1, Types...>>::type;
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

template<>
struct Generate<0>
{
	using type = IntList<>;
};

int main()
{
	using L1 = IntList<2, 3, 4>;
	using L2 = IntCons<1, L1>::type;
	using L3 = Generate<5>::type;
	std::cout << L3::Head << std::endl;
	int i;
	std::cin >> i;


    return 0;
}