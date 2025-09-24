#include "bridges.hpp"
#include <iostream>

int bridges_helper(const vector<Bridge> & bridges, vector<size_t> & chosen, size_t index)
{
	if (index >= bridges.size())
	{
		return 0;
	}
	int no_bridge_toll = bridges_helper(bridges, chosen, index+1);
	Bridge curr = bridges[index];
	
	for (auto bridge_index : chosen)
	{
		if ((curr[0] > bridges[bridge_index][0] && curr[1] < bridges[bridge_index][1])
			|| (curr[0] < bridges[bridge_index][0] && curr[1] > bridges[bridge_index][1])
			|| (curr[0] == bridges[bridge_index][0] || curr[1] == bridges[bridge_index][1]))
		{
			return no_bridge_toll;
		}
	}
	// Trying the bridge
	chosen.push_back(index);
	int with_bridge_toll = bridges_helper(bridges, chosen, index+1);
	with_bridge_toll += bridges[index][2];
	chosen.pop_back();
	return no_bridge_toll > with_bridge_toll ? no_bridge_toll : with_bridge_toll;
}

int bridges(int w, int e, const vector<Bridge> & bridges)
{
	// sort... please?
	vector<size_t> chosen;
	size_t index = 0; 
	return bridges_helper(bridges, chosen, index);
}