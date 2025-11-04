/**
 * bridges.cpp
 * Ashley Schultz
 *
 * LAST MODIFIED: 2025-11-03
 * Solution for CS411 HW 2
 * Source file for bridges function
 */

#include "bridges.hpp"
#include <algorithm>
//For std::sort and std::remove_if

// For the memory function to tell if it has calculated the value or not
#define UNKNOWN_VALUE -1

/*
 * Takes two bridges west cities (a and c) and east cities (b and d)
 * then checks if the bridges overlap.
 */
inline bool bridge_invalid(int a, int b, int c, int d) {
  return (((a > b) && (c < d)) || ((a < b) && (c > d)) || (a == b) || (c == d));
}

/**
 * Recursive function that recursively checks
 * all valid bridge combinations and finds the maximum toll.
 *
 * @param index current index of the bridges array the function checks
 * @param chosen chosen bridges in the current iteration
 * @param bridges list of bridges, see main function
 *
 * Preconditions:
 * 	bridges is a vector of vectors of size 3
 * 	chosen is empty initially
 * 	index is zero initially
 */
int bridges_helper(const vector<Bridge> &bridges, vector<size_t> &chosen,
                   size_t index, vector<size_t> & toll_table) {
  
  // BASE CASE
  // looked through all bridges, index is the size
  if (index >= bridges.size()) {
    return 0;
  }
  // RECURSIVE CASE
  // Try solutions without the bridge
  int no_bridge_toll = bridges_helper(bridges, chosen, index + 1, toll_table);
  Bridge curr = bridges[index];
  // Check solution
  for (auto bridge_index : chosen) {
    Bridge chosen_bridge = bridges[bridge_index];
    if (bridge_invalid(curr[0], chosen_bridge[0], curr[1], chosen_bridge[1])) {
      // If solution doesn't work with the bridge, return the toll without the
      // current bridge
      return no_bridge_toll;
    }
  }

  int with_bridge_toll = 0;
  if (toll_table[index] != UNKNOWN_VALUE)
  {
    with_bridge_toll = toll_table[index];
  } else {
    // Try solutions with the current bridge
    chosen.push_back(index);
    with_bridge_toll = bridges_helper(bridges, chosen, index + 1, toll_table);
    with_bridge_toll += curr[2];
    toll_table[index] = with_bridge_toll;
    // We have tried all solutions with the current bridge, pop it
    chosen.pop_back();
  }
  return no_bridge_toll > with_bridge_toll ? no_bridge_toll : with_bridge_toll;
}

// Helper function that removes bridges with equal west and east cities and
// sorts the input
// @param bridges vector of Bridges
void remove_equal_sort(vector<Bridge> &bridges) {
    std::sort(bridges.begin(), bridges.end(), [](const Bridge & a, const Bridge & b) {
    return a[0] < b[0] || // West City
           (a[0] == b[0] && a[1] < b[1]) ||  // Then East City
           (a[0] == b[0] && a[1] == b[1] && a[2] > b[2]); // Then Toll Descending Order
  });

  int last_e = -1, last_w = -1;
  auto it = std::remove_if(bridges.begin(), bridges.end(), [&](Bridge a) {
    bool is_same_cities = last_w == a[0] && last_e == a[1];
    last_e = a[0], last_w = a[1];
    return is_same_cities;
  });
  bridges.erase(it, bridges.end());
}
/**
 * bridges - wrapper for the recursive workhorse function
 * Returns the maximum toll given a list of bridges
 *
 *
 * 	@param w number of west cities
 * 	@param e number of east cities
 * 	@param bridges vector of available bridges.
 *
 * a bridge is a list of length 3 with:
 * 	  [west city, east city, toll]
 *
 * @pre
 * 	bridges must have west and east cities < w and < e
 *  bridges is a vector of vectors of size 3
 *
 */
int bridges(int w, int e, const vector<Bridge> &bridges) {
  // Array of indecies of chosen bridges
  vector<size_t> chosen;
  // Index of bridge being checked
  size_t index = 0;

  vector<Bridge> bridge_copy(bridges);

  vector<size_t> toll_table(bridge_copy.size(), UNKNOWN_VALUE);


  remove_equal_sort(bridge_copy);
  // Recursive function to exhaustively search bridge combinations
  return bridges_helper(bridge_copy, chosen, index, toll_table);
}