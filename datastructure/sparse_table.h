template<class T, T(*op)(T, T)>
struct sparse_table {
    int n;
    vector<vector<T>> table;

    sparse_table(vector<T> &a) : n(a.size()), table(__lg(n) + 1) {
        table[0] = a;
        for (int i = 1; i <= __lg(n); i++) {
            table[i].resize(n - (1 << i) + 1);
            for (int j = 0; j + (1 << i) <= n; j++) {
                table[i][j] = op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T query(int l, int r) {
        int i = __lg(r - l);
        return op(table[i][l], table[i][r - (1 << i)]);
    }
};
