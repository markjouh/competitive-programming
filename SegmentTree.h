template <typename T>
struct SegmentTree {
    int tree_sz;
    vector<T> tree;

    const T id = 0;

    T merge(T a, T b) {
        return a + b;
    }

    SegmentTree(int n) {
        init(n);
    }

    SegmentTree(vector<T> &a) {
        init(sz(a));
        build(a, 0, 0, tree_sz);
    }

    void init(int n) {
        tree_sz = 1;
        while (tree_sz < n) {
            tree_sz *= 2;
        }
        tree.resize(2 * tree_sz, id);
    }
    
    void build(vector<T> &a, int x, int tl, int tr) {
        if (tl + 1 == tr) {
            if (tl < sz(a)) {
                tree[x] = a[tl];
            }
            return;
        }
        int mid = tl + (tr - tl) / 2;
        build(a, 2 * x + 1, tl, mid);
        build(a, 2 * x + 2, mid, tr);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int i, int v, int x, int tl, int tr) {
        if (tl + 1 == tr) {
            tree[x] = v;
            return;
        }
        int mid = tl + (tr - tl) / 2;
        if (i < mid) {
            update(i, v, 2 * x + 1, tl, mid);
        } else {
            update(i, v, 2 * x + 2, mid, tr);
        }
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void update(int i, int v) {
        update(i, v, 0, 0, tree_sz);
    }

    T query(int l, int r, int x, int tl, int tr) {
        if (tl >= r || tr <= l) {
            return id;
        }
        if (tl >= l && tr <= r) {
            return tree[x];
        }
        int mid = tl + (tr - tl) / 2;
        return merge(query(l, r, 2 * x + 1, tl, mid), query(l, r, 2 * x + 2, mid, tr));
    }

    T query(int l, int r) {
        return query(l, r, 0, 0, tree_sz);
    }
};
