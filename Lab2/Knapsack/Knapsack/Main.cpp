#include "stdafx.h"
#include <iostream>
#include "Knapsack.h"
#include "Rand.h"

#define N 18
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	auxil::start();
	int V = 300;               // вместимость рюкзака              
	int v[N];     // размер предмета каждого типа  
	int	c[N];     // стоимость предмета каждого типа 
	short m[N];                // количество предметов каждого типа  {0,1}   
	clock_t  t1 = 0, t2 = 0;

	t1 = clock();
	for (int i = 0; i < N; i++)
	{
		v[i] = auxil::iget(10, 300);
	}
	for (int i = 0; i < N; i++)
	{
		c[i] = auxil::iget(5, 55);
	}

	int maxcc = knapsack_s(

		V,   // [in]  вместимость рюкзака 
		N,  // [in]  количество типов предметов 
		v,   // [in]  размер предмета каждого типа  
		c,   // [in]  стоимость предмета каждого типа     
		m    // [out] количество предметов каждого типа  
	);
	t2 = clock();

	std::cout << std::endl << "-------- Задача о рюкзаке --------- ";
	std::cout << std::endl << "- количество предметов : " << N;
	std::cout << std::endl << "- вместимость рюкзака  : " << V;
	std::cout << std::endl << "- размер + стоимость предметов  : "<<std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout<< i+1 <<". "<< v[i] << " - " <<c[i] << std::endl;
	}
	std::cout << std::endl << "- оптимальная стоимость рюкзака: " << maxcc;
	std::cout << std::endl << "- вес рюкзака: ";
	int s = 0; for (int i = 0; i < N; i++)
	{
		s += m[i] * v[i];
	}
	std::cout << s;
	std::cout << std::endl << "- выбраны предметы: ";
	for (int i = 0; i < N; i++)
	{
		std::cout << " " << m[i];
	}
	std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
	std::cout << std::endl << "                  (сек):   "
		<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl << std::endl;

	system("pause");
	return 0;
}
