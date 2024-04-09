template<typename T>
struct lazy_segtree {
    int n;
    vector<T> st, lz;

    const T id = 0;
    const T lz_id = 0;

    T merge(T a, T b) {
        return a + b;
    }

    void modify(T &a, T b) {
        a += b;
    }

    // depends on both the merge and modify!
    void push(int x, int tl, int tr) {
        if (lz[x] != lz_id) {
            st[x] += (tr - tl) * lz[x];
            if (tl + 1 != tr) {
                lz[2 * x + 1] += lz[x];
                lz[2 * x + 2] += lz[x];
            }
            lz[x] = lz_id;
        }
    }

    void init(int _n) {
        n = 1;
        while (n < _n) {
            n *= 2;
        }
        st.resize(2 * n, id);
        lz.resize(2 * n, lz_id);
    }

    lazy_segtree(int _n) {
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

    lazy_segtree(vector<T> &a) {
        init(a.size());
        build(a, 0, 0, n);
    }

    T query(int l, int r, int x, int tl, int tr) {
        push(x, tl, tr);
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

    void update(int l, int r, int v, int x, int tl, int tr) {
        push(x, tl, tr);
        if (tl >= r || tr <= l) {
            return;
        }
        if (tl >= l && tr <= r) {
            modify(st[x], v);
            if (tl + 1 != tr) {
                lz[2 * x + 1] += v;
                lz[2 * x + 2] += v;
            }
            return;
        }
        int mid = (tl + tr) / 2;
        update(l, r, v, 2 * x + 1, tl, mid);
        update(l, r, v, 2 * x + 2, mid, tr);
        st[x] = merge(st[2 * x + 1], st[2 * x + 2]);
    }

    void update(int l, int r, int v) {
        update(l, r, v, 0, 0, n);
    }

    void update(int i, int v) {
        update(i, i + 1, v, 0, 0, n);
    }
};
