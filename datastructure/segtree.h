template<class T, T(*op)(T, T), T(*id)()>
struct segtree {
    int n;
    vector<T> tree;

    segtree(int sz) : n(sz), tree(2 * n, id()) {}

    segtree(const vector<T> &a) : n(a.size()), tree(2 * n) {
        copy(a.begin(), a.end(), tree.begin() + n);
        for (int i = n - 1; i > 0; i--) {
            tree[i] = op(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    T query(int l, int r) {
        T ls = id(), rs = id();
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                ls = op(ls, tree[l++]);
            }
            if (r & 1) {
                rs = op(tree[--r], rs);
            }
        }
        return op(ls, rs);
    }

    void set(int p, T val) {
        for (tree[p += n] = val, p >>= 1; p > 0; p >>= 1) {
            tree[p] = op(tree[p << 1], tree[p << 1 | 1]);
        }
    }
};