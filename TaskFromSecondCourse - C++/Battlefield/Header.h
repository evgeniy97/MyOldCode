#pragma ones
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Fighter
{
protected:
	int hp;      // hit points
	int min_dmg; // minumum damage
	int max_dmg; // maximum damage
	int ini;     // initiative

public:

	Fighter(int _hp, int _min_dmg, int _max_dmg, int _ini) :hp(_hp), min_dmg(_min_dmg), max_dmg(_max_dmg), ini(_ini) // Конструктор и краткая инициализация
	{}

	virtual char* class_name() const
	{
		return "Fighter";
	}

	virtual int make_damage()
	{
		int dmg = rand() % (max_dmg - min_dmg) + min_dmg;
		cout << class_name() << "(" << hp << ") makes damage: " << dmg;
		return dmg;
	}

	virtual void receive_damage(int dmg)
	{
		hp -= dmg;
		cout << class_name() << " receives damage: " << dmg << " (" << hp << "). ";
	}

	bool alive() const //константная функция
	{
		return (hp > 0);
	}

	int get_hp() const //константная функция
	{
		return hp;
	}

	int get_ini() const
	{
		return ini;
	}
};

typedef vector<Fighter*> FArr;

class Elf : public Fighter
{
	int defl;
public:

	Elf(int _hp, int _min_dmg, int _max_dmg, int _ini, int _defl) : Fighter(_hp, _min_dmg, _max_dmg, _ini), defl(_defl)
	{}

	virtual char* class_name() const
	{
		return "Elf";
	}

	virtual void receive_damage(int dmg)
	{
		int p = rand() % 100;
		if (p <= defl)
			cout << class_name() << " avoid any damage (hp: " << hp << "). ";
		else
		{
			Fighter::receive_damage(dmg);
			//hp -= dmg;
			//cout << "Elf gets damage: " << dmg << " (hp: " << hp << ")";
		}
	}

private:

};


class Orc : public Fighter
{
public:

	int armor;
public:

	Orc(int _hp, int _min_dmg, int _max_dmg, int _ini, int _armor) : Fighter(_hp, _min_dmg, _max_dmg, _ini), armor(_armor)
	{}

	virtual char* class_name() const
	{
		return "Orc";
	}

	virtual void receive_damage(int dmg)
	{
		int absorbed_dmg = floor(dmg * float(armor) / 100.0);

		cout << class_name() << " armor absorb " << absorbed_dmg << " damage. ";
		Fighter::receive_damage(dmg - absorbed_dmg);
	}

private:

};

// функция-предикат для сравнения двух файтеров по инициативе
bool IniPred(Fighter* l, Fighter* r)
{
	return l->get_ini() < r->get_ini();
}

// функция-предикат для сравнения двух файтеров по хитпоинтам
bool HPPred(Fighter* l, Fighter* r)
{
	return l->get_hp() < r->get_hp();
}

// группа бойцов
class Party {
	string party_name;
	FArr fighters;
	int round_pos; // номер бойца, который бьет следующим

public:
	Party(const string& _pname) : round_pos(0), party_name(_pname)
	{}

	const char* get_name()
	{
		return party_name.c_str();
	}

	void start_round()
	{
		round_pos = 0;
	}

	// = true, если все живые бойцы уже сделали удар
	bool finished() const
	{
		return round_pos >= fighters.size();
	}

	void add_fighter(Fighter* f)
	{
		// если указатель f ненулевой, то добавить в массив бойцов
		if (f)
			fighters.push_back(f);

		// сортировка бойцов по параметру ini
		std::sort(fighters.begin(), fighters.end(), IniPred);
	}

	bool alive() const
	{
		for (int i = 0; i < fighters.size(); i++)
			if (fighters[i]->alive())
				return true;
		return false;
	}

	int get_count() const
	{
		return fighters.size();
	}

	virtual int make_damage()
	{
		if (!finished()) {
			cout << "Party " << party_name << " hits. ";
			return fighters[round_pos++]->make_damage(); // текущий боец генерирует дамагу и передает ход следующему
		}
		return 0;
	}

	virtual void receive_damage(int dmg)
	{
		// поиск бойца с максимальными хитпоинтами
		FArr::iterator it = max_element(fighters.begin(), fighters.end(), HPPred);

		cout << "Party " << party_name << " defends. ";
		// если найден такой боец, то
		if (it != fighters.end()) {
			(*it)->receive_damage(dmg); // он получает дамагу
			if ((*it)->get_hp() <= 0) { // если он при этом умер, то
				cout << (*it)->class_name() << " is dead.";
				delete (*it); // удалить из память объект
				fighters.erase(it); // удалить указатель на него из массива
			}
		}
		else
			cout << "Can't find fighter with max hp";
	}

	~Party() {
		for (int i = 0; i < fighters.size(); i++)
			if (fighters[i])
				delete fighters[i];
	}
};

class Dwarf :public Fighter // снижает урон на 30% с вероятностью 50%
{
	int Defl;
public:


	Dwarf(int _HP, int _min_DMG, int _max_DMG, int _ini, int _Defl) :Fighter(_HP, _min_DMG, _max_DMG,ini), Defl(_Defl)
	{
	}


	virtual void receive_damage(int DMG)
	{
		int p = rand() % 100;
		if (p <= Defl)
		{
			this->hp -= int(0.7 * DMG);
			cout << "Drawf get only 70% damage: " << int(0.7 * DMG) << "(HP: " << hp << ")";
		}
		else
		{
			this->hp -= DMG;
			cout << "Drawf gets damage: " << DMG << " (HP: " << hp << ")";
		}
	}


private:

};

class Wizard :public Fighter // с вероятностью 40% восстанавливает себе 80% от нанесено им же урона
{
	int Defl;
public:


	Wizard(int _HP, int _min_DMG, int _max_DMG, int _ini, int _Defl) :Fighter(_HP, _min_DMG, _max_DMG,ini), Defl(_Defl)
	{
	}

	virtual int make_damage()
	{
		int p = rand() % 100;
		int DMG = rand() % (this->max_dmg - this->min_dmg) + this->min_dmg;
		if (p <= Defl)
		{
			this->hp += int(0.8 * DMG);
			cout << "Wizard makes damage: " << DMG << " and resrore HP (HP: " << hp << ")";
		}
		else
		{
			cout << "Wizard makes damage: " << DMG;
		}

		return DMG;
	}


private:

};