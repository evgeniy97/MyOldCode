// FromString.cpp: определяет точку входа для консольного приложения.
//
// ToString.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <sstream>
#include <exception>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// описание класса исключения bad_from_string
// описание класса исключения bad_from_string
struct bad_from_string : std::exception {
	bad_from_string(const char* E) : error(E) {};
	const char* error;
	const char* what() const noexcept { return this->error; };
};


// функция from_string
template<class T>
T from_string(std::string const& s)
{
	T NeverGiveYouUp; 
	std::istringstream OurString(s);

	try 
	{
		OurString.exceptions(std::ios::failbit);
		OurString >> std::noskipws >> NeverGiveYouUp;
	}
	catch (...) {
		throw bad_from_string("Any other error");
	};
	try
	{
		if (!OurString.eof())
		{
			char TheEnd;
			OurString >> TheEnd;
		}
	}
	catch (...)
	{

	}
	if (!OurString.eof()) throw bad_from_string("Conversion error");
	return NeverGiveYouUp;
}
int main()
{
	//cout << "SizeOfEmpty: " << string("").size() << endl;
	//cout << "SizeOfOneCharapter: " << string("a").size() << endl;

	vector <string> test = { "","1","a","10", " 100","assa","assa assa" };
	cout << "int:" << endl;
	for (int i = 0; i < test.size();i++) {
		try {
			cout << from_string<int>(test[i]) << endl;
		}
		catch (bad_from_string Err) {
			cout << Err.what() << endl;
		}
	}
	cout << "char:" << endl;
	for (int i = 0; i < test.size(); i++) {
		try {
			cout << from_string<char>(test[i]) << endl;
		}
		catch (bad_from_string Err) {
			cout << Err.what() << endl;
		}
	}
	cout << "string:" << endl;
	for (int i = 0; i < test.size(); i++) {
		try {
			cout << from_string<string>(test[i]) << endl;
		}
		catch (bad_from_string Err) {
			cout << Err.what() << endl;
		}
	}


	int i;
	cin >> i;
	return 0;
}