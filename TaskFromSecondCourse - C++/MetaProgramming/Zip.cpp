// Zip.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

template <int ...T>
struct IntList;

template <int H, int ...T>
struct IntList<H, T...>
{
	static const int Head = H;
	using Tail = IntList<T...>;
};

template <>
struct IntList<> { };

// реализация метафункции IntCons

template<int H, typename TL>
struct IntCons;

template< int H, int... Types>
struct IntCons< H, IntList<Types...>>
{
	using type = IntList< H, Types...>;
};

// бинарная метафункция
template<int a, int b>
struct Plus
{
	static int const value = a + b;
};

template <int ...Ints, typename functional>
struct Zip < IntList<Ints...>, IntList<Ints...>,functional>  
{
	using type = IntList<>;
};


int main()
{

	using L1 = IntList<1, 2, 3, 4, 5>;
	using L2 = IntList<1, 3, 7, 7, 2>;

	using L3 = Zip<L1, L2, Plus>::type; 

    return 0;
}

