// Factory Method.cpp: ���������� ����� ����� ��� ����������� ����������.
//
//6. ������ ������� / ��������� ����� 
//a.����������� �������, ������� ����� ������������ �� ������������ �������� � ����������� �������� ��������� �����
//������� ����� �������� �� ������������ ��������, ������������� ����������� �������� ��������� ��������(��������� ���������, ����������, ���������, ������� ����� � ��.).
//������������ ������� ����� ����� �����������, ������� � ������� �������� ��������� ����� ��� ������� ����� ��������� ���������� ������� ��������.


#include "stdafx.h"
#include <vector>
#include <iostream>
//#include <cassert>  

 using namespace std;
class gadget;
class Fabric
{
public:
	virtual gadget* create() = 0;
	virtual ~Fabric() {}
	// ������������������� ����������� ��������� �����
};

class gadget
{
public:
	virtual void info() = 0;
};
class PC : public gadget
{
public:
	PC() { };
	void info() {
		cout << "PC" << endl;
	}
};
class Fabric_PC : public Fabric {
public:
	static gadget* create() {
		return new PC();
	};
};
class Phone : public gadget
{
public:
	void info() {
		cout << "Phone" << endl;
	}
};
class Fabric_Phone : public Fabric {
public:
	static gadget* create() {
		return new Phone();
	};
};
class Tablet : public gadget
{
public:
	void info() {
		cout << "Tablet" << endl;
	}
};

class Fabric_Tablet : public Fabric {
public:
	static gadget* create() {
		return new Tablet();
	};
};

int main()
{
	vector<gadget*> v;
	size_t i = -1;
	cout << "Chose thing to create:" << endl;
	cout << "[0] - Exit" << endl;
	cout << "[1] - PC" << endl;
	cout << "[2] - Phone" << endl;
	cout << "[3] - Tablet" << endl;
	do{
		cin >> i;
		switch (i) {
		case 1: v.push_back(Fabric_PC::create()); break;
		case 2: v.push_back(Fabric_Phone::create()); break;
		case 3: v.push_back(Fabric_Tablet::create()); break;
		default:;
		}
	} while (i != 0);
	cout << "Your List:" << endl;
	for (int i = 0; i<v.size(); i++)
		v[i]->info();

    return 0;
}

