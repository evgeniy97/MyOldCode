// test_2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "iostream"
#include <string>
#include <tuple>



void print_values(std::ostream & os);
template<typename T, typename... Args> void print_values(std::ostream & os, T value, Args... args);


// ��������� std::tuple ������������� �������
template < int N, int M,
	typename... Args,
	class A = typename std::tuple_element<N, std::tuple<Args...>>::type, 
	class B = typename std::tuple_element<M, std::tuple<Args...>>::type > 
	std::pair<A, B> to_pair(std::tuple<Args...> t)
{
	return std::pair<A, B>(std::get<N>(t),std::get<M>(t));
}

template<class F>
void for_each_int(int * p, int * q, F f)
{
	for (; p != q; ++p)
		f(*p);
}


int main()
{

	int m[10] = { 1,2,3,4,5,6,7,8,9,10 };


	auto square_fun = [](int *n) {return n * n; };

	for_each_int(m, m + 10, square_fun); // ������ m = {1,4,9,16,25,36,49,64,81,100};

	for (int i : m) {
		std::cout << m[i] << " ";
	}

	int i;
	std::cin >> i;
    return 0;
}

void print_values(std::ostream & os) {

}

template<typename T, typename... Args>
void print_values(std::ostream & os, T value, Args... args)
{
	if (&(value) != nullptr) {
		os << typeid(value).name() << ":" << value << std::endl;
		print_values(os, args...);
	}
}


template<class T>
struct Array
{
	// ��� ����������� ���� ������ ��� �����������
	explicit Array(size_t size = 0);
	Array(Array const& a);
	Array & operator=(Array const& a);
	~Array();

	size_t size() const;
	T &         operator[](size_t i);
	T const&    operator[](size_t i) const;

	// ���������� ������������ �����������
	Array(Array &&s) :
		size_(s.size()), data_(s.data_) {
		s.size_ = 0;
		s.data_ = nullptr;
	}
	// ���������� ������������ �������� ������������
	Array & operator= (Array &&s) {
		delete[] data_;
		data_ = s.data_;
		size_ = s.size_;
		s.data_ = nullptr;
		s.size_ = 0;
		return *this;
	}
private:
	size_t  size_;
	T *     data_;
};


//�������� ��������� ������� to_pair, ������� ��������� ������������ std::tuple
//� ��� ������� ������ � ���������� std::pair,
//���������� �������� ����������� std::tuple � ���������������� ���������.

//auto t = std::make_tuple(0, 3.5, "Hello");
//std::pair<double, char const *> p = to_pair<1, 2>(t);
// p �������� 3.5 � "Hello"

// ����������� ��������� Point ��� ����������
 struct Point
{
constexpr Point(double x, double y)
: x(x), y(y)
{}

double x = 0;
double y = 0;
};


// ��������
constexpr Point operator+ (const Point &first, const Point &second)
{
	return Point(first.x + second.x, first.y + second.y);
}

// ���������
constexpr Point operator- (const Point &first, const Point &second)
{
	return Point(first.x - second.x, first.y - second.y);
}

// ��������� ������������
constexpr double operator* (const Point &first, const Point &second)
{
	return (first.x * second.x + first.y * second.y);
}