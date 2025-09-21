#include "bridges.hpp"
#include <iostream>

int bridges(int w, int e, const vector<Bridge> & bridges) 
{
	size_t size = bridges.size();
	if (size < 1)
	{
		return 0;
	} else if (size == 1)
	{
		return bridges[0][2];
	}
	
	return 0;
}