// ToString.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <sstream>
#include <exception>
#include <iostream>
#include <fstream>

using namespace std;

// описание класса исключения bad_from_string
// описание класса исключения bad_from_string
struct bad_from_string : std::exception {
	bad_from_string(const char* E) : error(E) {};
	const char* error;
	const char* what() const noexcept { return this->error; };
};


class Cl {
	string i;
	int j, k;
public:
	friend istream& operator >> (istream& is, Cl& dt);
	friend ostream& operator << (ostream& is, Cl& dt);
};

istream & operator >> (istream & is, Cl & dt)
{
	is >> dt.i >> dt.j >> dt.k;
	return is;
}

ostream & operator<<(ostream & is, Cl & dt)
{
	is << dt.i << " " << dt.j << " "  << dt.k << " ";
	return is;
}

// функция from_string
template<class T>
T from_string(std::string const& s)
{
	T NeverGiveYouUp;
	char TheEnd;
	std::istringstream OurString(s);
	try { OurString >> std::noskipws >> NeverGiveYouUp >> TheEnd;
	cout << NeverGiveYouUp << endl;
	}
	catch (std::exception er) {
		cout << er.what() << endl;
	}
	if (!(OurString.eof())) throw bad_from_string("Conversion error");;
	return NeverGiveYouUp;
}
int main()
{

	try {
		string s2("Hi 12 12 ");
		Cl a2 = from_string<Cl>(s2); // исключение
		cout << a2 << endl;
	}
	catch (bad_from_string Err) {
		cout << Err.what() << endl;
	}
	int i;
	cin >> i;
    return 0;
}

