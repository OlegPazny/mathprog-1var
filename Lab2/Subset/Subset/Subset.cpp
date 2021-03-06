#include "stdafx.h"
#include <iostream>
#include "Combi.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	char  Set[] = { 'A','B', 'C', 'D' };

	std::cout << std::endl << " - Генератор множества всех подмножеств -";
	std::cout << std::endl << "Исходное множество: ";
	std::cout << "{ ";
	for (int i = 0; i < sizeof(Set); i++)
		std::cout << Set[i] << ((i< sizeof(Set) - 1) ? ", " : " ");
	std::cout << "}";
	std::cout << std::endl << "Генерация всех подмножеств  ";
	combi::subset Subset(sizeof(Set));         // создание генератора   
	int  n = Subset.getfirst();                // первое (пустое) подмножество    
	while (n >= 0)                          // пока есть подмножества 
	{
		std::cout << std::endl << "{ ";
		for (int i = 0; i < n; i++)
			std::cout <<Set[Subset.ntx(i)] << ((i< n - 1) ? ", " : " ");
		std::cout << "}";
		n = Subset.getnext();                   // cледующее подмножество 
	};
	std::cout << std::endl << "всего: " << Subset.count() << std::endl;
	system("pause");
	return 0;
}
