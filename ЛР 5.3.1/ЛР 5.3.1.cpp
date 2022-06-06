#include <algorithm>
#include <tchar.h>
#include <iostream>
#include "LCS.h"
// - main  
// -- вычисления длины LCS 
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	char X[] = "ALBDACD", Y[] = "CDLDCA";
	std::cout << std::endl << "-- вычисление длины LCS для X и Y(рекурсия)";
	std::cout << std::endl << "-- последовательность X: " << X;
	std::cout << std::endl << "-- последовательность Y: " << Y;
	int s = lcs(
		sizeof(X) - 1,  // длина   последовательности  X   
		"ALDC",       // последовательность X
		sizeof(Y) - 1,  // длина   последовательности  Y
		"LADCM"       // последовательность Y
	);
	std::cout << std::endl << "-- длина LCS: " << s << std::endl;
	system("pause");
	return 0;
}
int lcs(int lenx, const char x[],
	int leny, const char y[])
{
	int rc = 0;
	if (lenx > 0 && leny > 0)
	{
		if (x[lenx - 1] == y[leny - 1]) rc = 1 + lcs(lenx - 1, x, leny - 1, y);
		else rc = std::max(lcs(lenx, x, leny - 1, y), lcs(lenx - 1, x, leny, y));
	}
	return rc;        //длина LCS
}
