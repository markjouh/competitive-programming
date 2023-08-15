// Note: the size of the result will be < n if (and only if) there is a cycle.
vector<int> topsort(const vector<vector<int>> &g) {
    vector<int> in(sz(g));
    for (int u = 0; u < sz(g); u++) {
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
    vector<int> result;
    while (!q.empty()) {
        int u = q.front();
        a.pop();
        result.push_back(u);
        for (int v : g[u]) {
            if (--in[v] == 0) {
                q.push(v);
            }
        }
    }
    return result;
}
