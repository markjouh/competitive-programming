#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

// +-------------------------------+
// | CONSTANTS                     |
// +-------------------------------+

const string black_bold = "\033[30;1m";
const string magenta_bold = "\033[35;1m";
const string yellow = "\033[33m";
const string green = "\033[32;1m";
const string reset = "\033[0m";

// +-------------------------------+
// | CORE TYPES                    |
// +-------------------------------+

string format(const string &s) {
    return yellow + s + reset;
}

template<typename T, typename = decltype(to_string(declval<T>()))>
string format(const T &x) {
    return yellow + to_string(x) + reset;
}

// +-------------------------------+
// | ALL OVERLOADS                 |
// +-------------------------------+

template<typename T>
string format(const vector<T> &a);

template<typename T>
string format(const vector<vector<T>> &a);

template<typename T>
string format(const vector<vector<vector<T>>> &a);

template<typename T, size_t N>
string format(const array<T, N> &a);

template<typename T, size_t N, size_t M>
string format(const array<array<T, M>, N> &a);

template<typename T, size_t N, size_t M, size_t K>
string format(const array<array<array<T, K>, M>, N> &a);

template<typename T, typename U>
string format(const pair<T, U> &p);

template<typename K, typename V>
string format(const map<K, V> &mp);

template<typename K, typename V, typename H>
string format(const gp_hash_table<K, V, H> &mp);

template<typename T>
string format(const set<T> &s);

template<typename T>
string format(const tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> &s);

template<typename T>
string format(const stack<T> &s);

template<typename T>
string format(const queue<T> &q);

template<typename T, typename U, typename V>
string format(const priority_queue<T, U, V> &pq);

// +-------------------------------+
// | ARRAYS                        |
// +-------------------------------+

template<typename T>
string format(const vector<T> &a) {
    string res;
    bool first = true;
    for (auto &x : a) {
        if (!first) {
            res += ' ';
        }
        res += format(x);
        first = false;
    }
    return res;
}

template<typename T>
string format(const vector<vector<T>> &a) {
    int n = size(a), m = 0;
    for (int i = 0; i < n; i++) {
        m = max(m, int(size(a[i])));
    }

    vector<vector<string>> aligned(n, vector<string>(m));
    for (int i = 0; i < m; i++) {
        int mx_width = 0;
        for (int j = 0; j < n; j++) {
            if (i < int(size(a[j]))) {
                aligned[j][i] = format(a[j][i]);
            } else {
                aligned[j][i] = format(".");
            }
            mx_width = max(mx_width, int(size(aligned[j][i])));
        }
        for (int j = 0; j < n; j++) {
            aligned[j][i] = string(mx_width - int(size(aligned[j][i])), '.') + aligned[j][i];
        }
    }

    string res;
    for (auto &x : aligned) {
        res += '\n' + format(x);
    }
    return res;
}

template<typename T>
string format(const vector<vector<vector<T>>> &a) {
    string res;
    bool first = true;
    for (auto &x : a) {
        if (!first) {
            res += '\n' + green + string(25, '-') + reset;
        }
        res += format(x);
        first = false;
    }
    return res;
}

template<typename T, size_t N>
string format(const array<T, N> &a) {
    vector<T> vec(N);
    for (int i = 0; i < int(N); i++) {
        vec[i] = a[i];
    }
    return format(vec);
}

template<typename T, size_t N, size_t M>
string format(const array<array<T, M>, N> &a) {
    vector<vector<T>> vec(N, vector<T>(M));
    for (int i = 0; i < int(N); i++) {
        for (int j = 0; j < int(M); j++) {
            vec[i][j] = a[i][j];
        }
    }
    return format(vec);
}

template<typename T, size_t N, size_t M, size_t K>
string format(const array<array<array<T, K>, M>, N> &a) {
    string res;
    bool first = true;
    for (auto &x : a) {
        if (!first) {
            res += '\n' + green + string(25, '-') + reset;
        }
        res += format(x);
        first = false;
    }
    return res;
}

// +-------------------------------+
// | OTHER STL CONTAINERS          |
// +-------------------------------+

template<typename T, typename U>
string format(const pair<T, U> &p) {
    return yellow + '(' + reset + format(p.first) + yellow + " : " + reset + format(p.second) + yellow + ')' + reset;
}

template<typename K, typename V>
string format(const map<K, V> &mp) {
    vector<pair<K, V>> pairs;
    for (auto p : mp) {
        pairs.push_back(p);
    }
    return format(pairs);
}

template<typename K, typename V, typename H>
string format(const gp_hash_table<K, V, H> &mp) {
    vector<pair<K, V>> pairs;
    for (auto p : mp) {
        pairs.push_back(p);
    }
    return format(pairs);
}

template<typename T>
string format(const set<T> &s) {
    vector<T> vec(begin(s), end(s));
    return format(vec);
}

template<typename T>
string format(const tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> &s) {
    vector<T> vec(begin(s), end(s));
    return format(vec);
}

template<typename T>
string format(const stack<T> &s) {
    stack<T> tmp_s = s;
    vector<T> vec;
    while (!tmp_s.empty()) {
        vec.push_back(tmp_s.top());
        tmp_s.pop();
    }
    reverse(vec.begin(), vec.end());
    return format(vec);
}

template<typename T>
string format(const queue<T> &q) {
    queue<T> tmp_q = q;
    vector<T> vec;
    while (!tmp_q.empty()) {
        vec.push_back(tmp_q.front());
        tmp_q.pop();
    }
    return format(vec);
}

template<typename T, typename U, typename V>
string format(const priority_queue<T, U, V> &pq) {
    priority_queue<T, U, V> tmp_pq = pq;
    vector<T> vec;
    while (!tmp_pq.empty()) {
        vec.push_back(tmp_pq.top());
        tmp_pq.pop();
    }
    return format(vec);
}

// +-------------------------------+
// | DEBUG MACRO                   |
// +-------------------------------+

#define debug(...) cerr << black_bold << "[LINE #" << __LINE__ << "]\n" << reset; debug_out(#__VA_ARGS__, __VA_ARGS__)

void debug_out(string names) {
    assert(names.empty());
    cerr << endl;
}

template<typename T, typename... U>
void debug_out(string names, T first, U&&... rest) {
    int name_r = names.find(',');
    if (name_r == int(string::npos)) {
        name_r = size(names);
    }

    cerr << magenta_bold << names.substr(0, name_r) << reset << green << " = " << reset;
    names.erase(0, name_r + 2);

    cerr << format(first);

    if (sizeof...(rest) > 0) {
        cerr << '\n';
    }

    debug_out(names, rest...);
}

// +-------------------------------+
// | OTHER QOL FEATURES            |
// +-------------------------------+

auto t_begin = chrono::high_resolution_clock::now();

void output_time() {
    auto t_end = chrono::high_resolution_clock::now();
    cerr << setprecision(3) << fixed << '\n';
    cerr << black_bold << "[Execution time: " << chrono::duration_cast<std::chrono::duration<double>>(t_end - t_begin).count() << " seconds]" << reset << endl;
}

struct init_timer {
    init_timer() {
        assert(atexit(output_time) == 0);
    }
} init_timer_;
