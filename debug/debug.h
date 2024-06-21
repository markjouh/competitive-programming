#include <bits/stdc++.h>
#include <ranges>
#include <type_traits>

using namespace std;

template<class T>
T::value_type get_front(T &x) {
    typename T::value_type ret;
    if constexpr (ranges::range<T>) {
        ret = *x.begin();
        x.erase(x.begin());
    } else if constexpr (requires(T x) { x.front(); }) {
        ret = x.front();
        x.pop();
    } else if constexpr (requires(T x) { x.top(); }) {
        ret = x.top();
        x.pop();
    }
    return ret;
}

template<typename T>
void print(T x) {
    if constexpr (requires(T x) { cerr << x; }) {
        cerr << x;
    } else if constexpr (requires(T x) { x.first, x.second; }) {
        cerr << '(';
        print(x.first);
        cerr << ", ";
        print(x.second);
        cerr << ')';
    } else {
        cerr << '[';
        bool flag = false;
        while (!x.empty()) {
            if (flag) {
                cerr << ", ";
            }
            print(get_front(x));
            flag = true;
        }
        cerr << ']';
    }
}

template<typename T>
void print_debug(string s, T x) {
    cerr << s << " = ";
    print(x);
    cerr << endl;
}

template<typename T, typename... Args>
void print_debug(string s, T x, Args... args) {
    int idx = 0, layer = 0;
    while (idx < ssize(s) && (s[idx] != ',' || layer != 0)) {
        layer += s[idx] == '(' || s[idx] == '{';
        layer -= s[idx] == ')' || s[idx] == '}';
        idx++;
    }

    cerr << s.substr(0, idx) << " = ";
    print(x);
    cerr << " | ";
    print_debug(s.substr(s.find_first_not_of(' ', idx + 1)), args...);
}

#ifdef LOCAL
#define debug(...) print_debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif