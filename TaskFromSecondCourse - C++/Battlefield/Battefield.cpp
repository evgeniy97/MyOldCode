
// #include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <cmath>
#include "Header.h"
#include <vector>
#include <ctime>

using namespace std;

bool AnyAlive(const FArr& farr)
{
	for (int i = 0; i < farr.size(); i++)
		if (!farr[i]->alive())
			return false;
	return true;

}


int main()
{
	cout << "Welcome to the fight club!\nYou know rules of the club." << endl;
	srand(time(NULL));
	int i = 0; // номер раунда

			   // создание двух групп
	Party pOne("<HSE>"), pTwo("<MGU>");

	// добавление бойцов в первую группу
	pOne.add_fighter(new Elf(100, 10, 20, 5, 30));
	pOne.add_fighter(new Wizard(100, 12, 18, 4, 35));
	pOne.add_fighter(new Orc(100, 12, 18, 4, 35));

	// добавление бойцов во вторую группу
	pTwo.add_fighter(new Orc(100, 10, 20, 6, 30));
	pTwo.add_fighter(new Dwarf(100, 12, 18, 2, 35));
	pTwo.add_fighter(new Dwarf(100, 12, 18, 2, 35));

	// массив из указателей на группы, чтобы легко переключаться между ними
	Party* PS[] = { &pOne, &pTwo };
	const int PN = 2;
	bool a[PN];
	a[0] = PS[0]->alive();
	a[1] = PS[1]->alive();

	// цикл по раундам
	while (a[0] && a[1])
	{
		cout << "round: " << i << "\n";
		int j = i % 2;
		PS[0]->start_round(); // сброс номера бойца, бить будет первый в группе
		PS[1]->start_round();

		bool f[] = { true, true };

		// перебираются все бойцы команд пока обе команды живы и хотя бы одна не закончила бить
		while ((f[0] || f[1]) && a[0] && a[1])
		{
			f[j] = !PS[j]->finished();
			a[j] = PS[j]->alive();

			// если текущая команда не закончила бить, а противоположная жива, то
			if (f[j] && a[(j + 1) % PN]) {
				int dmg = PS[j]->make_damage(); // сгенерировать дамагу
				cout << endl;
				PS[(j + 1) % PN]->receive_damage(dmg); // отправить ее противоположной команде
				cout << endl;
			}
			j = (j + 1) % PN;
		}
		i++;
	}

	const char* pname = ((a[0]) ? (PS[0]->get_name()) : (PS[1]->get_name()));
	cout << "Party " << pname << " wins!" << endl;

	cin >> i;

	return 0;
}

