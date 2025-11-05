/**
 * bridges.cpp
 * Ashley Schultz
 *
 * LAST MODIFIED: 2025-11-04
 * Solution for CS411 HW 2
 * Source file for bridges function
 */

#include "bridges.hpp"
#include <algorithm>
// For std::sort, std::max, and std::remove_if

// For the memory function to tell if it has calculated the value or not
constexpr int UNKNOWN_VALUE = -1;

/**
 * Recursive function that recursively checks
 * valid bridge combinations and finds the maximum toll.
 *
 * @param bridges sorted array with duplicates removed
 * @param index current index of the bridges array
 * @param toll_table stored tolls previously calculated
 * optional parameters *
 * @param prev_w stores the value of last west city checked
 * @param prev_e stores the value of last east city checked
 *
 * Preconditions:
 *  start and end point to valid, sorted data, with equal bridges (bridges who
 * have the same west and east cities) removed, except for the bridge that is
 * equal to others and has the greatest toll. toll_table is filled with
 * UNKOWN_VALUES equal to the size of bridges
 *
 */
int bridges_helper(const vector<Bridge> &bridges, size_t index,
                   vector<size_t> &toll_table, int prev_w = -1,
                   int prev_e = -1) {

  // BASE CASE
  // looked through all bridges
  if (index >= bridges.size()) {
    return 0;
  }
  // RECURSIVE CASE
  // Try solutions without the bridge
  int no_bridge_toll =
      bridges_helper(bridges, index + 1, toll_table, prev_w, prev_e);
  const Bridge &curr = bridges[index];
  // Check solution
  if (!(curr[0] > prev_w && curr[1] > prev_e)) {
    // Since list of bridges is sorted, current bridges cities cannot be greater
    // then previous bridge cities
    return no_bridge_toll;
  }

  int with_bridge_toll = 0;
  if (toll_table[index] != UNKNOWN_VALUE) {
    with_bridge_toll = toll_table[index];
  } else {
    with_bridge_toll =
        bridges_helper(bridges, index + 1, toll_table, curr[0], curr[1]);
    with_bridge_toll += curr[2];
    toll_table[index] = with_bridge_toll;
  }
  return std::max(no_bridge_toll, with_bridge_toll);
}

// Helper function that removes bridges with equal west and east cities and
// sorts the input by east and west cities and by toll in descending order
// @param bridges vector of Bridges
void remove_equal_sort(vector<Bridge> &bridges) {
  std::sort(bridges.begin(), bridges.end(),
            [](const Bridge &a, const Bridge &b) {
              return a[0] < b[0] ||                   // West City
                     (a[0] == b[0] && a[1] < b[1]) || // Then East City
                     (a[0] == b[0] && a[1] == b[1] &&
                      a[2] > b[2]); // Then Toll Descending Order
            });

  bridges.erase(unique(bridges.begin(), bridges.end(),
                       [](const Bridge &a, const Bridge &b) {
                         return a[0] == b[0] && a[1] == b[1];
                       }),
                bridges.end());
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
  // vector<size_t> chosen;
  // Index of bridge being checked

  vector<Bridge> bridge_copy(bridges);

  vector<size_t> toll_table(bridge_copy.size(), UNKNOWN_VALUE);

  remove_equal_sort(bridge_copy);
  // Recursive function to exhaustively search bridge combinations
  return bridges_helper(bridges, 0, toll_table);
}