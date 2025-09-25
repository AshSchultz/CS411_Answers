#include "bridges.hpp"
/*
 * Takes two bridges east cities(a and c) and east cities (b and d)
 * then checks if the bridges overlap
 *  
*/ 
inline bool bridge_invalid(int a, int b, int c, int d)
{
	return (((a>b) && (c<d)) || ((a<b) && (c>d)) || (a==b) || (c==d));
}

int bridges_helper(const vector<Bridge> & bridges, vector<size_t> & chosen, size_t index)
{
	// BASE CASE
	// looked through all bridges, index is the size
	if (index >= bridges.size())
	{
		return 0;
	}
	// RECURSIVE CASE
	// Try solutions without the bridge
	int no_bridge_toll = bridges_helper(bridges, chosen, index+1);
	Bridge curr = bridges[index];
	// Check solution
	for (auto bridge_index : chosen)
	{
		Bridge chosen_bridge = bridges[bridge_index];
		if (bridge_invalid(curr[0], chosen_bridge[0], curr[1], chosen_bridge[1]))
		{
			// If solution doesn't work with the bridge, return the toll without the
			// current bridge
			return no_bridge_toll;
		}
	}
	// Try solutions with the current bridge
	chosen.push_back(index);
	int with_bridge_toll = bridges_helper(bridges, chosen, index+1);
	with_bridge_toll += curr[2];
	// We have tried all solutions with the current bridge, pop it
	chosen.pop_back();
	return no_bridge_toll > with_bridge_toll ? no_bridge_toll : with_bridge_toll;
}

int bridges(int w, int e, const vector<Bridge> & bridges)
{
	// Array of indecies of chosen bridges
	vector<size_t> chosen;
	// Index of bridge being checked
	size_t index = 0;
	// Recursive function to exhaustively search bridge combinations
	return bridges_helper(bridges, chosen, index);
}