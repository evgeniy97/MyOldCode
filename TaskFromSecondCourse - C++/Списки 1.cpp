//5.     Создать и протестировать функцию
//void arreySetToList(const  vector<set<int>> &src, list<int> &dst),
//которая сформирует список целых чисел dst из массива множеств целых чисел src по следующим правилам : 
//dst содержит только числа из множеств, содержащих числа меньше 10; 
//числа, принадлежащие одному множеству, отсортированы в порядке убывания; 
//числа, принадлежащие разным множествам отсортированы в порядке возрастания количества элементов в множествах, которым они принадлежали.
//Пример: src = { { 3,2,1 },{ 4,5,3,6 },{ 2,0,5,6 },{ 30,13,31 } } = > dst = { 3,2,1,6,5,4,3,0,2,5,6 }


#include "stdafx.h"
#include <iostream>
#include <list>
#include <set>
#include <vector>
#include <iterator>
#include <functional>
#include <cstdlib>
#include <algorithm>

using namespace std;

void arreySetToList(const  vector<set<int>> &src, list<int> &dst);
void function_v12(const  vector<set<int>> &src, int number);
void print_list(const vector<set<int>> &src);
void print_list(const list<int> &src);
vector <set<int>> copy_with_no_more_than_10(const vector<set<int>> &src);
list<int> create_list(const vector<set<int>> &src);
bool sort_function(const set<int> &a, const  set <int> &b) { return a.size() < b.size(); };

int main()
{
	function_v12({ { 3,2,1 },{ 4,5,3,6 },{ 2,0,5,6 },{ 30,13,31 } }, 0);
	function_v12({}, 1);
	function_v12({ { 10 },{ 10,11 } }, 2); // !!!
	function_v12({ {},{} }, 3);
	function_v12({ { 1,2,4,7,5 },{ 5,6,9,8,7,2 },{ 1,2,6,6 },{ 10,11,12,14 } }, 4);
	return 0;
}
void function_v12(const  vector<set<int>> &src, int number) {
	cout << "Test #" << number << endl;
	list <int> dst;
	if (!src.empty()) { // Проверяем пуст ли  данный нам вектор
		print_list(src);
		arreySetToList(src, dst);
	}
	else cout << "src is empty!" << endl;
}

void arreySetToList(const  vector<set<int>> &src, list<int> &dst) {
	vector <set <int>> n_src;
	n_src = copy_with_no_more_than_10(src);
	sort(n_src.begin(), n_src.end(), sort_function);
	//print_list(n_src);
	dst = create_list(n_src);
	print_list(dst);
}

void print_list(const vector<set<int>> &src) { 
	cout << "{";
	auto it = src.begin();
	for (size_t i = 0; i < src.size();i++) {
		set< int > a = *it;
		set<int>::iterator j; // что-то вроде указателя на элемент
		cout << "{";
		int k = 0;
		for (j = a.begin(); j != a.end(); ++j, ++k)
		{
			cout << *j;
			if (k != a.size() - 1)cout << ",";
		};
		cout << "}";
		if (i != src.size() - 1)cout << ",";
		advance(it, 1);
	}
	cout << "}" << endl;
}
void print_list(const list<int> &src) {
	cout << "Your new list:" << endl;
	if (!src.empty()) {
		cout << "{";
		int k = 0;
		for (auto j = src.begin(); j != src.end(); ++j, ++k)
		{
			cout << *j;
			if (k != src.size() - 1)cout << ",";
		};
		cout << "}" << endl;
	}
	else cout << "empty" << endl;
}

vector<set<int>> copy_with_no_more_than_10(const vector<set<int>> &src) {
	vector <set <int>> n_src;
	// vector <set <int> > ::iterator it; it = src.begin(); // Эта и следующая строка экввивалентны
	auto it = src.begin();
	for (size_t i = 0; i < src.size(); i++) { // size_t лучше для циклов, чем int
		if ((*it).lower_bound(10) == (*it).end()) {
			n_src.push_back((*it));
		};
		it++; 
	}
	return (n_src);
}

list<int> create_list(const vector<set<int>> &src) {
	list <int> dst;
	auto it = src.begin();
	for (size_t i = 0; i < src.size(); i++) {
		set< int > a = *it;
		for (auto j = a.rbegin(); j != a.rend(); ++j)
		{
			dst.push_back(*j);
		};
		advance(it, 1);
	}
	return dst;
}
