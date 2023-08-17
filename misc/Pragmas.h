/**
 * Author: Sergey Slotin
 * Date: 26 October 2021
 * Description: Auto-vectorization, may speed up code.
 * Change Ofast to O3 if working with floating point arithmetic.
 * Verification: https://codeforces.com/contest/1720/submission/219193438
 * Time: N/A
 */

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
