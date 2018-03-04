// TinkoffTask2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "vector"
#include "list"
#include <iterator>

int findCycles(std::vector <size_t> perestanovka) {
	std::list <int> answers;
	std::vector <bool> used; // В начале нигде не был
	for (int i = 0; i < perestanovka.size(); i++) used.push_back(0);

	for (int i = 0; i < perestanovka.size();i++)
	{
		int j = 0;
		if (!used[i]) j = i;
		std::vector<int> cycle;
			while (!used[j]) {
				cycle.push_back(perestanovka[j]);
				used[j] = 1;
				j = perestanovka[j];
			}
			//for (int k = 0; k < cycle.size(); k++) std::cout << cycle[k] << " ";
			//std::cout << std::endl;
		//if(cycle.size()) std::cout << cycle.size() << std::endl;
			if (cycle.size()) answers.push_back(cycle.size());
	}
	answers.unique();
	copy(answers.begin(), answers.end(), std::ostream_iterator<int>(std::cout, " "));
	return 0;
}

int main()
{
	size_t N = 0;
	std::vector <size_t> perestanovka;
	std::cin >> N;
	for (size_t i = 0; i < N; i++) { 
		size_t n = 0;
		std::cin >> n;
		perestanovka.push_back(n -1); 
	}
	findCycles(perestanovka);
	std::cin >> N;
    return 0;
}

