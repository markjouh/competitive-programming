#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

struct segtree {
    int siz;
    vector<ll> tree, lazy;

    void init(int n) {
        siz = 1;
        while (siz < n) {
            siz *= 2;
        }
        tree.resize(2 * siz);
        lazy.resize(2 * siz);
    }

    void build(vector<int> &a, int x, int l, int r) {
        if (l == r - 1) {
            if (l < sz(a)) {
                tree[x] = a[l];
            }
            return;
        }
        int mid = l + (r - l) / 2;
        build(a, 2 * x + 1, l, mid);
        build(a, 2 * x + 2, mid, r);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void build(vector<int> &a) {
        build(a, 0, 0, siz);
    }

    void update(int L, int R, int x, int l, int r, int v) {
        if (lazy[x] != 0) {
            tree[x] += (r - l) * lazy[x];
            if (l != r - 1) {
                lazy[2 * x + 1] += lazy[x];
                lazy[2 * x + 2] += lazy[x];
            }
            lazy[x] = 0;
        }
        if (l >= R || r <= L) {
            return;
        }
        if (l >= L && r <= R) {
            tree[x] += 1ll * (r - l) * v;
            if (l != r - 1) {
                lazy[2 * x + 1] += v;
                lazy[2 * x + 2] += v;
            }
            return;
        }
        int mid = l + (r - l) / 2;
        update(L, R, 2 * x + 1, l, mid, v);
        update(L, R, 2 * x + 2, mid, r, v);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void update(int L, int R, int v) {
        update(L, R, 0, 0, siz, v);
    }

    int query(int L, int R, int x, int l, int r) {
        if (lazy[x] != 0) {
            tree[x] += (r - l) * lazy[x];
            if (l != r - 1) {
                lazy[2 * x + 1] += lazy[x];
                lazy[2 * x + 2] += lazy[x];
            }
            lazy[x] = 0;
        }
        if (l >= R || r <= L) {
            return 0;
        }
        if (l >= L && r <= R) {
            return tree[x];
        }
        int mid = l + (r - l) / 2;
        return query(L, R, 2 * x + 1, l, mid) + query(L, R, 2 * x + 2, mid, r);
    }

    int query(int L, int R) {
        return query(L, R, 0, 0, siz);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
