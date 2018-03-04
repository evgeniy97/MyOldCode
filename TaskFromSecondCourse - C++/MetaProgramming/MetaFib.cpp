// MetaFib.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

template<int N>struct Fib { 
	static int const
		value = Fib<N - 2>::value + Fib<N - 1>::value;
}; 
template<>struct Fib<0> { 
	static int const value = 0; 
}; 
template<>struct Fib<1> {
	static int const value = 1;
};
int main() {
	std::cout << Fib<0>::value << std::endl;
	std::cout << Fib<1>::value << std::endl;
	std::cout << Fib<2>::value << std::endl;
	std::cout << Fib<3>::value << std::endl;
	std::cout << Fib<4>::value << std::endl;
	std::cout << Fib<5>::value << std::endl;
	std::cout << Fib<6>::value << std::endl;
	std::cout << Fib<7>::value << std::endl;

	int i;
	std::cin >> i;
}

