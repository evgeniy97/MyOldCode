// AdvancrdCppTask_1_2.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "string"
#include "iostream"


// этот класс уже определЄн выше
struct Unit
{
explicit Unit(size_t id)
: id_(id)
{}

size_t id() const { return id_; }

private:
size_t id_;
};


// базовый класс дл€ животных
struct Animal: virtual Unit
{
	// name хранит название животного
	// "bear" дл€ медвед€
	// "pig" дл€ свиньи
	Animal(std::string const & name, size_t id) : Unit(id), name_(name) {};
	std::string const& name() const { return name_; }
private:
	std::string name_;
};

// класс дл€ человека
struct Man: virtual Unit
{
	explicit Man(size_t id) : Unit(id) {};
};

// класс дл€ медвед€
struct Bear: Animal
{
	explicit Bear(size_t id) : Unit(id), Animal("bear", id) {};
};

// класс дл€ свиньи
struct Pig: Animal
{
	explicit Pig(size_t id) : Unit(id), Animal("pig",id) {};
};

// класс дл€ челмедведосвина
struct ManBearPig: Man,Bear,Pig
{
	ManBearPig(size_t id) : Unit(id), Man(id), Bear(id), Pig(id) {};
};

int main() {
	ManBearPig* my_unit = new ManBearPig(100);
	std::cout << my_unit->id() << std::endl;
}
