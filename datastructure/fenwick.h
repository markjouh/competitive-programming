template<class T>
struct fenwick {
    int n;
    vector<T> tree;

    fenwick(int sz) : n(sz), tree(n + 1) {}

    fenwick(vector<T> &a) : n(int(a.size())), tree(n + 1) {
        for (int i = 1; i <= n; i++) {
            tree[i] += a[i - 1];
            if (i + (i & (-i)) <= n) {
                tree[i + (i & (-i))] += tree[i];
            }
        }
    }

    T query(int r) {
        T res = 0;
        while (r > 0) {
            res += tree[r];
            r -= r & (-r);
        }
        return res;
    }

    T query(int l, int r) {
        return query(r) - query(l);
    }

    void update(int p, T v) {
        for (p++; p <= n; p += p & (-p)) {
            tree[p] += v;
        }
    }
};
