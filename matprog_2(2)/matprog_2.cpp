﻿// -- main 
#include "Auxil.h"
#include <iostream>
#include <iomanip> 
#include <time.h>
#include "Salesman.h"
#include <tchar.h>
#define SPACE(n) std::setw(n)<<" "
#define N 15 // число стоит 14, чтобы на выходе было 7 рассчетов (осторожно, долго считает!!!)
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");
    int d[N * N + 1], r[N];
    auxil::start();
    for (int i = 0; i <= N * N; i++) d[i] = auxil::iget(10, 100);
    std::cout << std::endl << "-- Задача коммивояжера -- ";
    std::cout << std::endl << "-- количество ------ продолжительность -- ";
    std::cout << std::endl << "      городов           вычисления  ";
    clock_t t1, t2;
    for (int i = 5; i <= N; i++) // вот твой цикл, начинается с 7, он выведет 6 значений, это и будет твой ответ :>
    {
        t1 = clock();
        salesman(i, (int*)d, r);
        t2 = clock();
        std::cout << std::endl << SPACE(7) << std::setw(2) << i
            << SPACE(15) << std::setw(5) << (t2 - t1);
    }
    std::cout << std::endl;
    system("pause");
    return 0;
}
