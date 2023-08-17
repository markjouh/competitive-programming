/**
 * Author: Jay Leeds
 * Date: Unknown
 * Description: Code to aid with debugging locally.
 * Verification: N/A
 * Time: N/A
 */

#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <string>
#include <utility>

void __print(int x) { std::cerr << x; }
void __print(long x) { std::cerr << x; }
void __print(long long x) { std::cerr << x; }
void __print(unsigned x) { std::cerr << x; }
void __print(unsigned long x) { std::cerr << x; }
void __print(unsigned long long x) { std::cerr << x; }
void __print(float x) { std::cerr << x; }
void __print(double x) { std::cerr << x; }
void __print(long double x) { std::cerr << x; }
void __print(char x) { std::cerr << '\'' << x << '\''; }
void __print(const char *x) { std::cerr << '\"' << x << '\"'; }
void __print(const std::string &x) { std::cerr << '\"' << x << '\"'; }
void __print(bool x) { std::cerr << (x ? "true" : "false"); }

template<typename T, typename V>
void __print(const std::pair<T, V> &x);
template<typename T>
void __print(const T &x) { int f = 0; std::cerr << '{'; for (const auto &i : x) std::cerr << (f++ ? ", " : ""), __print(i); std::cerr << "}"; }
template<typename T, typename V>
void __print(const std::pair<T, V> &x) { std::cerr << '{'; __print(x.first); std::cerr << ", "; __print(x.second); std::cerr << '}'; }
void _print() { std::cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) { __print(t); if (sizeof...(v)) std::cerr << ", "; _print(v...); }

#define dbg(x...) std::cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = ["; _print(x); std::cerr << "\e[39m" << std::endl;

#endif // DEBUG_H
