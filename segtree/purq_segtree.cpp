struct segtree {
    int siz;
    vector<ll> tree;

    void init(int n) {
        siz = 1;
        while (siz < n) {
            siz *= 2;
        }
        tree.resize(2 * siz);
    }

    void upd(int i, int v, int x, int l, int r) {
        if (l + 1 == r) {
            tree[x] = v;
            return;
        }
        int mid = l + (r - l) / 2;
        if (i < mid) {
            upd(i, v, 2 * x + 1, l, mid);
        } else {
            upd(i, v, 2 * x + 2, mid, r);
        }
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void upd(int i, int v) {
        upd(i, v, 0, 0, siz);
    }

    void build(vector<int> &a, int x, int l, int r) {
        if (l + 1 == r) {
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

    ll query(int L, int R, int x, int l, int r) {
        if (l >= R || r <= L) {
            return 0;
        }
        if (l >= L && r <= R) {
            return tree[x];
        }
        int mid = l + (r - l) / 2;
        return query(L, R, 2 * x + 1, l, mid) + query(L, R, 2 * x + 2, mid, r);
    }

    ll query(int l, int r) {
        return query(l, r, 0, 0, siz);
    }
};
