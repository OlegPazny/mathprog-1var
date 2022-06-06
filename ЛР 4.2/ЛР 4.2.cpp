// - main  
#include <iostream>
#include "Levenshtein.h"
#include <tchar.h>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Levenshtein.h"
#define N 300
#define P 250
#include <iomanip>
#include <algorithm>
#include "Levenshtein.h"
#define DD(i,j) d[(i)*(ly+1)+(j)] 

int min3(int x1, int x2, int x3)
{
    return std::min(std::min(x1, x2), x3);
}

int levenshtein(int lx, const char x[], int ly, const char y[])
{
    int* d = new int[(lx + 1) * (ly + 1)];
    for (int i = 0; i <= lx; i++) DD(i, 0) = i;
    for (int j = 0; j <= ly; j++) DD(0, j) = j;
    for (int i = 1; i <= lx; i++)
        for (int j = 1; j <= ly; j++)
        {
            DD(i, j) = min3(DD(i - 1, j) + 1, DD(i, j - 1) + 1,
                DD(i - 1, j - 1) + (x[i - 1] == y[j - 1] ? 0 : 1));
        }
    return DD(lx, ly);
}

int levenshtein_r(
    int lx, const char x[],
    int ly, const char y[]
)
{
    int rc = 0;
    if (lx == 0) rc = ly;
    else  if (ly == 0) rc = lx;
    else  if (lx == 1 && ly == 1 && x[0] == y[0]) rc = 0;
    else  if (lx == 1 && ly == 1 && x[0] != y[0]) rc = 1;
    else  rc = min3(
        levenshtein_r(lx - 1, x, ly, y) + 1,
        levenshtein_r(lx, x, ly - 1, y) + 1,
        levenshtein_r(lx - 1, x, ly - 1, y) + (x[lx - 1] == y[ly - 1] ? 0 : 1)
    );
    return rc;
};

int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");
    clock_t t1 = 0, t2 = 0, t3 = 0, t4 = 0;
    char x[N], y[P];
    for (int i = 0; i < N; i++)
        x[i] = ('a' + rand() % ('z' - 'a'));
    for (int i = 0; i < P; i++)
        y[i] = ('a' + rand() % ('z' - 'a'));
    std::cout << "S1: ";
    for (int i = 0; i < N; i++)
    {
        std::cout << x[i];
    }
    std::cout << "\n";
    std::cout << "S2: ";
    for (int i = 0; i < P; i++)
    {
        std::cout << y[i];
    }
    int  lx = sizeof(x) - 1, ly = sizeof(y) - 1;
    std::cout << std::endl;
    std::cout << std::endl << "-- расстояние Левенштейна --" << std::endl;
    std::cout << std::endl << "--- длина --- рекурсия --- дин.програм. ---"
        << std::endl;
    int d = 25;
    int lenthX;
    int lenthY;
    while (d > 0)
    {
        lenthX = N / d;
        lenthY = P / d;
        char* str1 = new char[lenthX];
        char* str2 = new char[lenthY];
        for (int i = 0; i < lenthX; i++)
        {
            str1[i] = x[i];
            std::cout << str1[i];
        }
        std::cout << std::endl;
        for (int i = 0; i < lenthY; i++)
        {
            str2[i] = y[i];
            std::cout << str2[i];
        }
        std::cout << std::endl;
        t1 = clock(); levenshtein_r(lenthX, str1, lenthY, str2); t2 = clock();
        t3 = clock(); levenshtein(lenthX, str1, lenthY, str2); t4 = clock();
        std::cout << std::right << 1 << "/" << std::setw(2) << d
            << "        " << std::left << std::setw(10) << (t2 - t1)
            << "   " << std::setw(10) << (t4 - t3) << std::endl << std::setw(2);
        if (d == 5) d -= 3;
        else if (d == 2) d -= 1;
        else d -= 5;
        delete[] str1;
        delete[] str2;
    }
    system("pause");
    return 0;
}
