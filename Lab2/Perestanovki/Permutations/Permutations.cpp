#include "stdafx.h"
#include <iostream>
#include "Combi.h"
#include <iomanip> 

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	char  Set[] = { 'A', 'B', 'C', 'D' };

	std::cout << std::endl << " --- Генератор перестановок ---";
	std::cout << std::endl << "Исходное множество: ";
	std::cout << "{ ";
	for (int i = 0; i < sizeof(Set); i++)
	{
		std::cout << Set[i] << ((i< sizeof(Set) - 1) ? ", " : " ");
	}			
	std::cout << "}";

	std::cout << std::endl << "Генерация перестановок ";
	combiP::permutation p(sizeof(Set));
	int  n = p.getfirst();
	while (n >= 0)
	{
		std::cout << std::endl << std::setw(4) << p.np << ": { ";
		for (int i = 0; i < p.n; i++)
		{
			std::cout << Set[p.ntx(i)] << ((i< p.n - 1) ? ", " : " ");
		}
		std::cout << "}";
		n = p.getnext();
	}

	std::cout << std::endl << "всего: " << p.count() << std::endl;
	system("pause");
	return 0;
}
