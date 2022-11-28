struct S_DSU {
    vector<int> siz, par;
    vector<vector<int>> cont;

    void init(int n) {
        siz.resize(n, 1);
        par.resize(n, -1);
        cont.resize(n);
        for (int i = 0; i < n; i++) {
            cont[i] = {i};
        }
    }

    int get_root(int u) {
        if (par[u] == -1) {
            return u;
        }
        return par[u] = get_root(par[u]);
    }

    // O(m + n * log(n)) for m queries on n elements.
    void unite(int a, int b) {
        a = get_root(a);
        b = get_root(b);
        if (a == b) {
            return;
        }
        if (siz[a] < siz[b]) {
            swap(a, b);
        }
        par[b] = a;
        siz[a] += siz[b];
        for (int x : cont[b]) {
            cont[a].push_back(x);
            par[x] = a;
        }
        cont[b].clear();
    }
}
