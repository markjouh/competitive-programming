/**
 * Author: Mark Zhou
 * Date: 15 August 2023
 * Description: Perform static range queries in O(1).
 * Merge function must be idempotent, meaning that it doesn't matter
 * if some item is considered more than once while querying.
 * Verification: https://judge.yosupo.jp/submission/155954
 * Time: O(n * log(n)) to build, O(1) to query
 */

template <typename T>
struct SparseTable {
    vector<vector<T>> table;

    T merge(T a, T b) {
        return min(a, b);
    }

    SparseTable(vector<T> &a) : table(log2_floor(sz(a)) + 1, vector<T>(sz(a))) {
        table[0] = a;
        for (int i = 1; i <= log2_floor(sz(a)); i++) {
            for (int j = 0; j + (1 << i) <= sz(a); j++) {
                table[i][j] = merge(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int log2_floor(unsigned long i) {
        return bit_width(i) - 1;
    }

    T query(int l, int r) {
        int i = log2_floor(r - l);
        return merge(table[i][l], table[i][r - (1 << i)]);
    }
};
