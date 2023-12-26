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
 
    T query(int l, int r) {
        T ret = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ret += tree[l++];
            if (r & 1) ret += tree[--r];
        }
        return ret;
    }
 
    void update(int p, T v) {
        for (tree[p += n] = v, p >>= 1; p > 0; p >>= 1) {
            tree[p] = tree[p << 1] + tree[p << 1 | 1];
        }
    }
};
