vector<int> topsort(vector<vector<int>> g) {
    // O(V + E), res.size() < n if the graph isn't a DAG
    int n = sz(g);
    vector<int> in(n);
    for (int u = 0; u < n; u++) {
        for (int v : g[u]) {
            in[v]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    vector<int> res;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for (int v : g[u]) {
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
    return res;
}
