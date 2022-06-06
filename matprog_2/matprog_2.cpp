// main 
#include <iostream>
#include <iomanip> 
#include <tchar.h>
#include <stdio.h>
#include "Salesman.h"
#define N 5
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");
    int d[N][N] = { //0   1    2    3     4    5    6    7    8     9      
                   { INF,   2 * 1,   21 + 1, INF,  1},    //  0
                   { 1,     INF,   15 + 1, 68 - 1, 84 - 1},    //  1
                   { 2 + 1,   3 * 1,   INF,  86,   49 + 1},    //  2 
                   { 17 + 1,  58 - 1,  4 * 1,  INF,  3 * 1},    //  3
                   { 93 - 1,  66 + 1,  52,   13 + 1, INF} }; //  4 

    int r[N];                     // результат 
    int s = salesman(
        N,          // [in]  количество городов 
        (int*)d,          // [in]  массив [n*n] расстояний 
        r           // [out] массив [n] маршрут 0 x x x x  

    );
    std::cout << std::endl << "-- Задача коммивояжера -- ";
    std::cout << std::endl << "-- количество  городов: " << N;
    std::cout << std::endl << "-- матрица расстояний : ";
    for (int i = 0; i < N; i++) {
        std::cout << std::endl;
        for (int j = 0; j < N; j++)
            if (d[i][j] != INF) std::cout << std::setw(3) << d[i][j] << " ";
            else std::cout << std::setw(3) << "INF" << " ";
    }
    std::cout << std::endl << "-- оптимальный маршрут: ";
    for (int i = 0; i < N; i++) std::cout << r[i] << "-->"; std::cout << 0;
    std::cout << std::endl << "-- длина маршрута     : " << s;
    std::cout << std::endl;
    system("pause");
    return 0;
}
