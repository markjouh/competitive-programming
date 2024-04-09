struct binlift {
    int n, lg;
    vector<int> dep;
    vector<vector<int>> up;
 
    binlift(vector<vector<int>> &g) : n(g.size()), lg(__lg(n) + 1), dep(n, -1), up(lg, vector<int>(n, -1)) {
        queue<int> q;
        dep[0] = 0;
        q.push(0);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (dep[v] == -1) {
                    dep[v] = dep[u] + 1;
                    up[0][v] = u;
                    q.push(v);
                }
            }
        }
        for (int i = 1; i < lg; i++) {
            for (int j = 0; j < n; j++) {
                if (up[i - 1][j] != -1) {
                    up[i][j] = up[i - 1][up[i - 1][j]];
                }
            }
        }
    }
 
    int anc(int x, int k) {
        for (int i = 0; i < lg; i++) {
            if (x != -1 && (k >> i) & 1) {
                x = up[i][x];
            }
        }
        return x;
    }
 
    int lca(int a, int b) {
        if (dep[a] < dep[b]) {
            swap(a, b);
        }
        a = anc(a, dep[a] - dep[b]);
        if (a == b) {
            return a;
        }
        for (int i = lg - 1; i >= 0; i--) {
            if (up[i][a] != up[i][b]) {
                a = up[i][a];
                b = up[i][b];
            }
        }
        return up[0][a];
    }
 
    int dist(int a, int b) {
        return dep[a] + dep[b] - 2 * dep[lca(a, b)];
    }
}
