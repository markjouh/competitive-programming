template <typename T>
struct SegmentTree {
    int n;
    const T id = 0;
    vector<T> st;

    T merge(T a, T b) {
        return a + b;
    }

    SegmentTree(int _n) : n(_n), st(2 * n, id) {}

    SegmentTree(vector<T> &a) : n(a.size()), st(2 * n) {
        for (int i = 0; i < n; i++) {
            st[n + i] = a[i];
        }
        for (int i = n - 1; i > 0; i--) {
            st[i] = merge(st[i << 1], st[i << 1 | 1]);
        }
    }

    T query(int l, int r) {
        T ls = id, rs = id;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ls = merge(ls, st[l++]);
            if (r & 1) rs = merge(st[--r], rs);
        }
        return merge(ls, rs);
    }

    void update(int p, T v) {
        for (st[p += n] += v, p >>= 1; p > 0; p >>= 1) {
            st[p] = merge(st[p << 1], st[p << 1 | 1]);
        }
    }
};
