#include <bits/stdc++.h>

using namespace std;

// +-------------------------------+
// | Constants                     |
// +-------------------------------+

// https://stackoverflow.com/a/75985833
const string black_bold = "\033[30;1m";
const string magenta_bold = "\033[35;1m";
const string yellow = "\033[33m";
const string green = "\033[32;1m";
const string reset = "\033[0m";

// +-------------------------------+
// | Core types (never expanded)   |
// +-------------------------------+

string format(const string &s) {
    return yellow + s + reset;
}

template<typename T, typename = decltype(to_string(declval<T>()))>
string format(const T &x) {
    return yellow + to_string(x) + reset;
}

// +-------------------------------+
// | All overloads                 |
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

template<typename T>
string format(const set<T> &s);

template<typename T>
string format(const stack<T> &s);

template<typename T>
string format(const queue<T> &q);

template<typename T, typename U, typename V>
string format(const priority_queue<T, U, V> &pq);

// +-------------------------------+
// | Array types                   |
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
    return yellow + res + reset;
}

template<typename T>
string format(const vector<vector<T>> &a) {
    const int n = size(a), m = size(a[0]);

    vector<vector<string>> aligned(n, vector<string>(m));
    for (int i = 0; i < m; i++) {
        int mx_width = 0;
        for (int j = 0; j < n; j++) {
            aligned[j][i] = format(a[j][i]);
            mx_width = max(mx_width, int(size(aligned[j][i])));
        }
        for (int j = 0; j < n; j++) {
            aligned[j][i] = string(mx_width - int(size(aligned[j][i])), ' ') + aligned[j][i];
        }
    }

    string res;
    for (auto &x : aligned) {
        res += '\n' + format(x);
    }
    return yellow + res + reset;
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
// | Other STL containers          |
// +-------------------------------+

template<typename T, typename U>
string format(const pair<T, U> &p) {
    return yellow + '(' + format(p.first) + ", " + format(p.second) + ')' + reset;
}

template<typename K, typename V>
string format(const map<K, V> &mp) {
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
// | Debug macros/actual usage     |
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
// | Other QOL features            |
// +-------------------------------+

auto t_begin = chrono::high_resolution_clock::now();

void output_time() {
    auto t_end = chrono::high_resolution_clock::now();
    cerr << setprecision(5) << fixed << '\n';
    cerr << black_bold << "[Execution time: " << chrono::duration_cast<std::chrono::duration<double>>(t_end - t_begin).count() << " seconds]" << reset << endl;
}

struct init_timer {
    init_timer() {
        assert(atexit(output_time) == 0);
    }
} init_timer_;