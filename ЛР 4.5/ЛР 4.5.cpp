// --- MultiMatrix.cpp 
//    расстановка скобок (рекурсия) 
#include <memory.h>
#include "MultyMatrix.h"
#define INFINITY  0x7fffffff
#define NINFINITY 0x80000000
#include <cmath>
#include <memory.h>
#include <iostream>

#define N 6
int OptimalM(int i, int j, int n, const int c[], int* s)
{
#define OPTIMALM_S(x1,x2)  (s[(x1-1)*n+x2-1])  
	int o = INFINITY, bo = INFINITY;
	if (i < j)
	{
		for (int k = i; k < j; k++)
		{
			bo = OptimalM(i, k, n, c, s) +
				OptimalM(k + 1, j, n, c, s) + c[i - 1] * c[k] * c[j];
			if (bo < o)
			{
				o = bo;
				OPTIMALM_S(i, j) = k;
			}
		}
	}
	else  o = 0;
	return o;
#undef OPTIMALM_S             
};
// --- MultyMatrix.cpp (продолжение) 
//    расстановка скобок (динамическое программирование)  
int OptimalMD(int n, const int c[], int* s)
{
#define OPTIMALM_S(x1,x2)  (s[(x1-1)*n+x2-1]) 
#define OPTIMALM_M(x1,x2)  (M[(x1-1)*n+x2-1])
	int* M = new int[n * n], j = 0, q = 0;
	for (int i = 1; i <= n; i++) OPTIMALM_M(i, i) = 0;
	for (int l = 2; l <= n; l++)
	{
		for (int i = 1; i <= n - l + 1; i++)
		{
			j = i + l - 1;
			OPTIMALM_M(i, j) = INFINITY;
			for (int k = i; k <= j - 1; k++)
			{
				q = OPTIMALM_M(i, k) + OPTIMALM_M(k + 1, j) + c[i - 1] * c[k] * c[j];
				if (q < OPTIMALM_M(i, j))
				{
					OPTIMALM_M(i, j) = q;  OPTIMALM_S(i, j) = k;
				}
			}
		}
	}
	return OPTIMALM_M(1, n);
#undef OPTIMALM_M
#undef OPTIMALM_S 
};


// --- main  
//    расстановка скобок  

int main()
{

	int Mc[N + 1] = { 5,10,15,20,25,30,35 }, Ms[N][N], r = 0, rd = 0;

	memset(Ms, 0, sizeof(int) * N * N);
	r = OptimalM(1, N, N, Mc, OPTIMALM_PARM(Ms));
	setlocale(LC_ALL, "rus");
	std::cout << std::endl;
	std::cout << std::endl << "-- расстановка скобок (рекурсивное решение) "
		<< std::endl;
	std::cout << std::endl << "размерности матриц: ";
	for (int i = 1; i <= N; i++) std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
	std::cout << std::endl << "минимальное количество операций умножения: " << r;
	std::cout << std::endl << std::endl << "матрица S" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
	}
	std::cout << std::endl;

	memset(Ms, 0, sizeof(int) * N * N);
	rd = OptimalMD(N, Mc, OPTIMALM_PARM(Ms));
	std::cout << std::endl
		<< "-- расстановка скобок (динамичеое программирование) " << std::endl;
	std::cout << std::endl << "размерности матриц: ";
	for (int i = 1; i <= N; i++)
		std::cout << "(" << Mc[i - 1] << "," << Mc[i] << ") ";
	std::cout << std::endl << "минимальное количество операций умножения: "
		<< rd;
	std::cout << std::endl << std::endl << "матрица S" << std::endl;
	for (int i = 0; i < N; i++)
	{
		std::cout << std::endl;
		for (int j = 0; j < N; j++)  std::cout << Ms[i][j] << "  ";
	}
	std::cout << std::endl << std::endl;
	system("pause");

	return 0;
}
