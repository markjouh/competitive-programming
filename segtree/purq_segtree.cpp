struct Tree {
    typedef int T;

    T f(T a, T b) {
        return min(a, b);
    }

    int siz;
    vector<T> tree;

    void init(int n) {
        siz = 1;
        while (siz < n) {
            siz *= 2;
        }
        tree.resize(2 * siz);
    }

    void update(int i, int v, int x, int l, int r) {
        if (l + 1 == r) {
            tree[x] = v;
            return;
        }
        int mid = l + (r - l) / 2;
        if (i < mid) {
            update(i, v, 2 * x + 1, l, mid);
        } else {
            update(i, v, 2 * x + 2, mid, r);
        }
        tree[x] = f(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int i, int v) {
        update(i, v, 0, 0, siz);
    }

    void build(vector<T> &a, int x, int l, int r) {
        if (l + 1 == r) {
            if (l < sz(a)) {
                tree[x] = a[l];
            }
            return;
        }
        int mid = l + (r - l) / 2;
        build(a, 2 * x + 1, l, mid);
        build(a, 2 * x + 2, mid, r);
        tree[x] = f(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(vector<T> &a) {
        init(sz(a));
        build(a, 0, 0, siz);
    }

    T query(int L, int R, int x, int l, int r) {
        if (l >= R || r <= L) {
            return 0;
        }
        if (l >= L && r <= R) {
            return tree[x];
        }
        int mid = l + (r - l) / 2;
        return f(query(L, R, 2 * x + 1, l, mid), query(L, R, 2 * x + 2, mid, r));
    }

    T query(int l, int r) {
        return query(l, r, 0, 0, siz);
    }
};
