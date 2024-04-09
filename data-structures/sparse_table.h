template<typename T>
struct sparse_table {
    vector<vector<T>> table;

    sparse_table(vector<T> &a) : table(__lg(sz(a)) + 1, vector<T>(sz(a))) {
        table[0] = a;
        for (int i = 1; i <= __lg(sz(a)); i++) {
            for (int j = 0; j + (1 << i) <= sz(a); j++) {
                table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T query(int l, int r) {
        int i = __lg(r - l);
        return min(table[i][l], table[i][r - (1 << i)]);
    }
};
