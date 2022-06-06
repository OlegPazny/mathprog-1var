#include <iostream>
#include <iomanip> 
#include <tchar.h>
#include <stdio.h>
#include "Salesman.h"
#define N 5
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");
    int d[N][N] = { //0   1    2    3     4        
                   {  0,  45, INF,  25,   50},    //  0
                   { 45,   0,  55,  20,  100},    //  1
                   { 70,  20,   0,  10,   30},    //  2 
                   { 80,  10,  40,   0,   10},    //  3
                   { 30,  50,  20,  10,    0} };   //  4 
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


int sum(int x1, int x2) // суммирование с учетом бесконечности 
{
    return (x1 == INF || x2 == INF) ? INF : (x1 + x2);
};
int* firstpath(int n)   // формирование 1го маршрута 0,1,2,..., n-1, 0
{
    int* rc = new int[n + 1]; rc[n] = 0;
    for (int i = 0; i < n; i++) rc[i] = i;
    return rc;
};
int* source(int n)      // формирование исходного массива 1,2,..., n-1
{
    int* rc = new int[n - 1];
    for (int i = 1; i < n; i++) rc[i - 1] = i;
    return rc;
};
void  copypath(int n, int* r1, const int* r2)   // копировать маршрут
{
    for (int i = 0; i < n; i++)  r1[i] = r2[i];
};
int distance(int n, int* r, const int* d)       // длина маршрута 
{
    int rc = 0;
    for (int i = 0; i < n - 1; i++) rc = sum(rc, d[r[i] * n + r[i + 1]]);
    return  sum(rc, d[r[n - 1] * n + 0]);    //+ последняя дуга (n-1,0) 
};
void indx(int n, int* r, const int* s, const short* ntx) {
    for (int i = 1; i < n; i++)  r[i] = s[ntx[i - 1]];
}
int salesman(
    int n,         // [in]  количество городов 
    const int* d,  // [in]  массив [n*n] расстояний 
    int* r         // [out] массив [n] маршрут 0 x x x x 
) {
    int* s = source(n), * b = firstpath(n), rc = INF, dist = 0;
    combi3::permutation p(n - 1);
    int k = p.getfirst();
    while (k >= 0)  // цикл генерации перестановок
    {
        indx(n, b, s, p.sset);        // новый маршрут 
        if ((dist = distance(n, b, d)) < rc) { rc = dist; copypath(n, r, b); }
        k = p.getnext();
    };
    return rc;
}
