// Adapter.cpp: определяет точку входа для консольного приложения.
//

//4. Шаблон Адаптер(Adapter) 
//a.Реализовать проект, который будет показывать аналоговые(стрелочные) часы.
//Необходимо реализовать логику обычных цифровых часов и с помощью паттерна 
//Адаптер перевести данную логику на логику аналоговых часов.
//При помощи основного класса, который отвечает за логику цифровых часов и паттерна Адаптер реализовать работу аналоговых часов.


#include "stdafx.h"
#include "string"
#include "iostream"
#include <math.h>

using namespace std;

class time;
class target;
class analog;

class time {
public:
	int T,t;
	time() : T(0),t(0) {}
	time(int _T, int _t) : T(( _T + _t/60 ) % 24),t( _t % 60) {}
	//virtual void Print() = 0;
};
// Target
class target {
	//virtual ~target() {}
	virtual void Print() = 0;
};

// "Adapter"
class analog : target{
private:
	time* TIME;
public:
	analog(time* _TIME) : TIME(_TIME) {
	}
	~analog() {
		delete TIME;
	}
	void Print() {
		cout << "TIME IS " << (TIME->T) % 12 << " : " << TIME->t << endl;;
	}
};

int main()
{
	int I, J;
	cout << "GET TIME" << endl;
	cin >> I >> J;
	analog* TIME = new analog( new time(I, J));
	TIME->Print();
    return 0;
}

