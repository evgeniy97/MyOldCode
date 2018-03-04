// ListTask.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "list"

// так как в задании не указан тип элементов,
// которые хранятся в списке, то давайте сделаем
// эту функцию шаблонной
// Параметр It — это тип итератора 
template<class It>
size_t max_increasing_len(It p, It q)
{
	if (p == q) return 0;

	auto previous = p;
	size_t len = 1, len_max = 0;

	for (; p != q; ++p) {
		//std::cout << "pr: " << *previous << " now: " << *p << std::endl;
		if (*p > *previous) {
			len++;
			previous = p;
		}
		else {
			if (len_max < len) len_max = len;
			len = 1;
			previous = p;
		}
	}
	return len > len_max? len: len_max;
}


int main()
{
	std::list<int> const l1 = { 7,8,9,4,5,6,1,2,3,4,2 };
	size_t len1 = max_increasing_len(l1.begin(), l1.end()); // 4, соответствует подотрезку 1,2,3,4
	std::cout << "len:" << len1 << std::endl;

	std::list<int> const l2 = { -3,-2,-1,0,0,1,2,3,4,5 };
	size_t len2 = max_increasing_len(l2.begin(), l2.end()); // 6, соответствует подотрезку 0,1,2,3,4,5
	std::cout << "len:" << len2 << std::endl;

	std::list<int> const l3 = {};
	size_t len3 = max_increasing_len(l3.begin(), l3.end()); // 0
	std::cout << "len:" << len3 << std::endl;

	std::list<int> const l4 = {1,1,1,1,1,1,1,1,1,1};
	size_t len4 = max_increasing_len(l4.begin(), l4.end()); // 1
	std::cout << "len:" << len4 << std::endl;

	std::list<int> const l5 = { 5,4,3,2,1,0};
	size_t len5 = max_increasing_len(l5.begin(), l5.end()); // 1
	std::cout << "len:" << len5 << std::endl;

	std::list<int> const l6 = {1,2,3,4,5,6};
	size_t len6 = max_increasing_len(l6.begin(), l6.end()); // 6
	std::cout << "len:" << len6 << std::endl;

	std::list<int> const l7 = { 1,1,1,2,1,1,1};
	size_t len7 = max_increasing_len(l7.begin(), l7.end()); // 2
	std::cout << "len:" << len7 << std::endl;

	int i;
	std::cin >> i;
    return 0;
}

