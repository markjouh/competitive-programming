template<typename T>
struct mergesort_tree {
    int n;
    vector<ordered_set<T>> tree;

    mergesort_tree(int _n) {
        n = 1;
        while (n < _n) {
            n *= 2;
        }
        tree.resize(2 * n);
    }

    void update(int p, T v, int x, int tl, int tr) {
        tree[x].insert(v);

        if (tl + 1 == tr) {
            return;
        }

        int mid = (tl + tr) / 2;
        if (p < mid) {
            update(p, v, 2 * x + 1, tl, mid);
        } else {
            update(p, v, 2 * x + 2, mid, tr);
        }
    }

    void update(int p, T v) {
        update(p, v, 0, 0, n);
    }

    int query(int l, int r, T v, int x, int tl, int tr) {
        if (tl >= r || tr <= l) {
            return 0;
        }
        if (tl >= l && tr <= r) {
            return tree[x].order_of_key(v);
        }
        int mid = (tl + tr) / 2;
        return query(l, r, v, 2 * x + 1, tl, mid) + query(l, r, v, 2 * x + 2, mid, tr);
    }

    int query(int l, int r, int v) {
        return query(l, r, v, 0, 0, n);
    }
};
