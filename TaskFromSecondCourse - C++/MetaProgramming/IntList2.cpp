// IntList2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

// ���������� ������
template <int  ...>
struct IntList {};

// ������������� ��� ������� ������
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

// ������ ��������
template<int H>
struct Generate<H>
{
	using T = Generate<H - 1, IntList<H - 1>>;
	using type = T::type;
	//using type = IntList<Generate<H-1>,H-1>
};
// ��� ��������
// #1
template<int H, int... Types>
struct Generate<H, IntList<Types...> >
{
	using T = Generate<H - 1, IntList<H - 1, Types...>>;
	using type = T::type;
};
// ����� ���������
template<int... Types>
struct Generate<1, IntList<Types...> >
{
	using type = IntList<0, Types...>;
};
// ��� ������ Generate<1>
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

