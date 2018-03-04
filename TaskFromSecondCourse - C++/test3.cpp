// test3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "functional"

template<class F>
void for_each_int(int * p, int * q, F f)
{
	for (; p != q; ++p)
		f(*p);
}

template<class F>
bool find_if(int * p, int * q, F f)
{
	for (; p != q; ++p)
		if (f(*p))
			return true;
	return false;
}

int main()
{
	//int m[10] = { 1,2,3,4,5,6,7,8,9,10 };

	//std::function<void(int&)> square_fun = [](int &n) { n = n*n; };

	//for_each_int(m, m + 10, square_fun); // теперь m = {1,4,9,16,25,36,49,64,81,100};

	//for (int i = 0; i < 10; i++ ) {
	//	std::cout << m[i] << " ";
	//}

	int primes[5] = { 2,3,5,7,11 };

	int m[10] = { 0,0,1,1,4,6,7,8,9,10 };
	auto gen_finder = [](int* begin, int* end) {
		return [begin, end](int k) {
			int* a = begin;
			for (; a != end; a++) if (*a == k) return true;
			return false;
		};
	};
		
	//	[](int* begin, int* end) {
	//	return ([](int k) {
	//		std::cout << k << std::endl;
	//		return false;
	//	};
	//	);
	//};
	// has_prims будет истиной, т.к. в m есть число 7
	bool has_primes = find_if(m, m + 10, gen_finder(primes, primes + 5));
	std::cout << has_primes;

	//gen_finder(primes,primes+5);
	std::cout << std::endl;
	int i;
	std::cin >> i;

    return 0;
}

