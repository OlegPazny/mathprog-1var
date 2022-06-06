#include "stdafx.h"
#include "Combi.h"
#include <algorithm>
namespace combiC
{
	xcombination::xcombination(short n, short m)
	{
		this->n = n;
		this->m = m;
		this->sset = new short[m]; 
		this->reset();
	}
	void  xcombination::reset()     
	{
		this->nc = 0;
		for (int i = 0; i < this->m; i++)
		{
			this->sset[i] = i;
		}
		this->sset[m] = this->n;
	};
	short xcombination::getfirst()
	{
		return (this->n >= this->m) ? this->m : -1;
	};
	short xcombination::getnext()    
	{
		short rc = getfirst();
		if (rc > 0)
		{
			short j;
			for (j = 0; this->sset[j] + 1 == this->sset[j + 1]; ++j) 
				this->sset[j] = j;
			if (j >= this->m)
			{
				rc = -1;
			}
			else
			{
				this->sset[j]++;
				this->nc++;
			}
		}
		return rc;
	};
	short xcombination::ntx(short i)
	{
		return this->sset[i];
	};


	unsigned __int64 factC(unsigned __int64 x)
	{
		return(x == 0) ? 1 : (x*factC(x - 1));
	};

	unsigned __int64 xcombination::count() const
	{
		return (this->n >= this->m) ?
			factC(this->n) / (factC(this->n - this->m)*factC(this->m)) : 0;
	};
};
