#include <algorithm>
#include <array>
#include <bitset>
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
// | ANSI escape codes             |
// +-------------------------------+

const string red_bold = "\033[31;1m";
const string megenta_bold = "\033[35;1m";
const string yellow = "\033[33m";
const string green = "\033[32;1m";
const string reset = "\033[0m";

// +-------------------------------+
// | Output options                |
// +-------------------------------+

struct option_t {
    uint8_t v;

    option_t(int x) : v(x) {}
};

const option_t grid_mode(0);
const option_t binary_mode(1);

bool in_grid_mode = false;
bool in_binary_mode = false;

// +-------------------------------+
// | Core types                    |
// +-------------------------------+

string format(const string &s) {
    return yellow + s + reset;
}

template<typename T, typename = enable_if_t<is_integral<T>::value>>
string format(const T& x) {
    if (in_binary_mode) {
        return yellow + bitset<8>(x).to_string() + reset;
    }

    return yellow + to_string(x) + reset;
}

template<typename T, typename = enable_if_t<!is_integral<T>::value && !is_same<T, string>::value>, typename = decltype(to_string(declval<T>()))>
string format(const T &x) {
    return yellow + to_string(x) + reset;
}

string format(const option_t &o) {
    switch (o.v) {
        case 0:
            in_grid_mode = true;
            return "enabled";
            break;
        case 1:
            in_binary_mode = true;
            return "enabled";
            break;
        default:
            return "undefined option";
    }
}

// +-------------------------------+
// | Overloads                     |
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
// | Vectors and arrays            |
// +-------------------------------+

template<typename T>
string format(const vector<T> &a) {
    string res;
    bool first = true;
    for (auto &x : a) {
        if (!first) {
            res += ", ";
        }
        res += format(x);
        first = false;
    }
    return '{' + res + '}';
}

template<typename T>
string format(const vector<vector<T>> &a) {
    if (in_grid_mode) {
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
                }
                mx_width = max(mx_width, int(size(aligned[j][i])));
            }
            for (int j = 0; j < n; j++) {
                aligned[j][i] = string(mx_width - int(size(aligned[j][i])), ' ') + aligned[j][i];
            }
        }

        string res;
        bool first = true;
        for (auto &x : aligned) {
            if (!first) {
                res += ",\n";
            }
            res += " " + format(x);
            first = false;
        }
        return "{\n" + res + "\n}";
    }
    

    string res;
    bool first = true;
    for (auto &x : a) {
        if (!first) {
            res += ", ";
        }
        res += format(x);
        first = false;
    }
    return '{' + res + '}';
}

template<typename T>
string format(const vector<vector<vector<T>>> &a) {
    string res;
    bool first = true;
    for (auto &x : a) {
        if (!first) {
            res += ", ";
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
// | Other stl containers          |
// +-------------------------------+

template<typename T, typename U>
string format(const pair<T, U> &p) {
    return yellow + '{' + reset + format(p.first) + yellow + ", " + reset + format(p.second) + yellow + '}' + reset;
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
// | Debug macro                   |
// +-------------------------------+

#define debug(...) cerr << red_bold << "[LINE #" << __LINE__ << "]\n" << reset; debug_out(#__VA_ARGS__, __VA_ARGS__)

void debug_out(string names) {
    assert(names.empty());

    in_grid_mode = false;
    in_binary_mode = false;

    cerr << endl;
}

template<typename T, typename... U>
void debug_out(string names, T first, U&&... rest) {
    int name_r = names.find(',');
    if (name_r == int(string::npos)) {
        name_r = size(names);
    }

    cerr << megenta_bold << names.substr(0, name_r) << reset << green << " = " << reset;
    names.erase(0, name_r + 1 + (name_r + 1 < int(size(names)) && names[name_r + 1] == ' '));

    cerr << format(first);

    if (sizeof...(rest) > 0) {
        cerr << '\n';
    }

    debug_out(names, rest...);
}

// +-------------------------------+
// | Timer                         |
// +-------------------------------+

auto t_begin = chrono::high_resolution_clock::now();

void output_time() {
    auto t_end = chrono::high_resolution_clock::now();
    cerr << setprecision(3) << fixed << '\n';
    cerr << red_bold << "[Execution time: " << chrono::duration_cast<std::chrono::duration<double>>(t_end - t_begin).count() << " seconds]" << reset << endl;
}

struct init_timer {
    init_timer() {
        assert(atexit(output_time) == 0);
    }
} init_timer_;
