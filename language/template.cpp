#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define FOR(i, l, r) for (int i = l; i < r; i++)
#define F0R(i, n) FOR(i, 0, n)
#define ROF(i, l, r) for (int i = r - 1; i >= l; i--)
#define R0F(i, n) ROF(i, 0, n)

#define sz(x) int(size(x))
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using ll = long long;
using ld = long double;

template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T> bool ckmin(T &a, const T b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T b) { return b > a ? a = b, 1 : 0; }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

void solve() {
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}