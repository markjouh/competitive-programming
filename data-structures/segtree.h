template<typename T>
struct segtree {
    int n;
    vector<T> st;

    const T id = 0;

    T merge(T a, T b) {
        return a + b;
    }

    void modify(T &a, T b) {
        a += b;
    }

    void init(int _n) {
        n = 1;
        while (n < _n) {
            n *= 2;
        }
        st.resize(2 * n, id);
    }

    segtree(int _n) {
        init(_n);
    }

    void build(vector<T> &a, int x, int tl, int tr) {
        if (tl + 1 == tr) {
            if (tl < int(a.size())) {
                st[x] = a[tl];
            }
            return;
        }
        int mid = (tl + tr) / 2;
        build(a, 2 * x + 1, tl, mid);
        build(a, 2 * x + 2, mid, tr);
        st[x] = merge(st[2 * x + 1], st[2 * x + 2]);
    }

    segtree(vector<T> &a) {
        init(a.size());
        build(a, 0, 0, n);
    }

    T query(int l, int r, int x, int tl, int tr) {
        if (tl >= r || tr <= l) {
            return id;
        }
        if (tl >= l && tr <= r) {
            return st[x];
        }
        int mid = (tl + tr) / 2;
        return merge(query(l, r, 2 * x + 1, tl, mid), query(l, r, 2 * x + 2, mid, tr));
    }

    T query(int l, int r) {
        return query(l, r, 0, 0, n);
    }

    T query(int i) {
        return query(i, i + 1, 0, 0, n);
    }

    void update(int i, T v, int x, int tl, int tr) {
        if (tl + 1 == tr) {
            modify(st[x], v);
            return;
        }
        int mid = (tl + tr) / 2;
        if (i < mid) {
            update(i, v, 2 * x + 1, tl, mid);
        } else {
            update(i, v, 2 * x + 2, mid, tr);
        }
        st[x] = merge(st[2 * x + 1], st[2 * x + 2]);
    }

    void update(int i, T v) {
        update(i, v, 0, 0, n);
    }
};
