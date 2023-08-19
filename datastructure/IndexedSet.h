/**
 * Description: Supports queries for the kth largest element and for the number of elements less than k in log time.
 * Verification: https://codeforces.com/contest/1860/problem/C
 */

#include <ext/pb_ds/assoc_container.hpp>

// find_by_order(k) - The item at index k
// order_of_key(k) - Count items < k
template <typename T> using indexed_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
