template<typename T>
struct ST {
    int n;
    vector<T> tree;

    ST(int _n) : n(_n), tree(2 * n) {}

    ST(vector<T> &a) : n(a.size()), tree(2 * n) {
        for (int i = 0; i < n; i++) {
            tree[i + n] = a[i];
        }
        for (int i = n - 1; i > 0; i--) {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }

    T query(int p) {
        T ret = 0;
        for (tree[p += n]; p > 0; p >>= 1) {
            ret += tree[p];
        }
        return ret;
    }
 
    void update(int l, int r, T v) {
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) tree[l++] += v;
            if (r & 1) tree[--r] += v;
        }
    }
};
