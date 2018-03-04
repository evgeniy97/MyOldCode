// Observer.cpp: определяет точку входа для консольного приложения.
//
// 7. Шаблон Наблюдатель(Observer)
// b. Реализовать программу чата, которая будет стоять из четырех текстовых полей.
// Каждое поле может посылать сообщения другому определенному полю.
//Реализовать данную систему с применением шаблона наблюдатель.
//Паттерн наблюдатель будет следить за отправкой каждого сообщения 
//и сообщать нужному окну чата то, что на его имя пришло сообщение и его содержание.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class chat;
class Observer;
class window;

class chat {
	vector < class Observer * > views;
public:
	void attach(Observer *obs) {
		views.push_back(obs);
	};
	chat() {};
	void notify();
};

class Observer {
	chat *Chat;

public:
	Observer(chat *_Chat) {
		Chat = _Chat;
		// Наблюдатели регистрируются у субъекта
		Chat->attach(this);
	}
	virtual void update() = 0;
protected:
};
class window : public Observer {
	// Номер окна
	size_t Number;
	// Сообщения в окне
	vector <string> message;
public:
	window(chat *_Chat, size_t _Number) : Observer(_Chat), Number (_Number) {}
	void update() {
		//  "Вытягивание" интересующей информации
		cout << "In window#" << this->Number  << ":" << endl;
		for (size_t i = 0; i < message.size(); i++) cout << message[i] << endl;
		// Освобождаем буфер сообщений 
		for (size_t i = 0; i < message.size(); i++) message.pop_back();
	}
	void send(window *to, string _message) {
		string MESSAGE = "          from window#";
		MESSAGE += to_string(this->Number);
		MESSAGE += ": ";
		MESSAGE += _message;
		to->get(MESSAGE);
	}
	void get(string _message) {
		message.push_back(_message);
	}
};
void chat::notify() {
	//  Извещение наблюдателей
	for (int i = 0; i < views.size(); i++)
		views[i]->update();
	cout << "---------------------------------------" << endl;
};
int main()
{

	chat Chat;

	window Win1(&Chat,1);
	window Win2(&Chat,2);
	window Win3(&Chat,3);
	window Win4(&Chat,4);

	Win1.send(&Win2,"HI!");
	Win2.send(&Win4, "Hello!");
	Win1.send(&Win3, "What's up?");
	Win3.send(&Win1,"I made smtg");

	Chat.notify();

	Win1.send(&Win4, "Bonjor!");
	Win2.send(&Win4, "Good morning!");
	Win1.send(&Win3, "LALALALA");
	Win3.send(&Win1, "42");

	Chat.notify();

	return 0;
}
