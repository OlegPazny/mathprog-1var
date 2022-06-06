#pragma once 
namespace combiP
{
	struct  permutation    // генератор   перестановок     
	{
		const static bool L = true;  // левая стрелка 
		const static bool R = false; // правая стрелка   

		short  n,              // количество элементов исходного множества 
			*sset;           // массив индексов текущей перестановки
		bool  *dart;           // массив  стрелок (левых-L и правых-R) 
		permutation(short n = 1); // конструктор (количество элементов исходного множества) 

		void reset();                // сбросить генератор, начать сначала 

		int getfirst();          // сформировать первый массив индексов    
		int getnext();           // сформировать случайный массив индексов  

		short ntx(short i);          // получить i-й элемент масива индексов 
		unsigned int np;         // номер перествновки 0,... count()-1 

		unsigned int count() const;  // вычислить общее кол. перестановок    
	};
};

