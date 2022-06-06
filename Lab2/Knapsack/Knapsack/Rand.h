#pragma once
#include "stdafx.h"
//¬ключение этого заголовка гарантирует, что имена, объ€вленные с помощью внешней компоновки в заголовке стандартной библиотеки C,
//объ€вл€ютс€ в пространстве имен std.
#include <cstdlib>

namespace auxil
{
	void start();
	double dget(double rmin, double rmax);
	int iget(int rmin, int rmax);
}