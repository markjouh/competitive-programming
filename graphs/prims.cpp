int prims(vector<vector<pii>> g) {
    // O((V + E) * log(V))
    int ans = 0;
    vector<int> cost(n, 1e9);
    vector<int> vis(n);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    cost[0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        auto [w, u] = q.top();
        q.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        ans += w;
        for (auto [edge_w, v] : g[u]) {
            if (!vis[v] && edge_w < cost[v]) {
                cost[v] = edge_w;
                q.push({edge_w, v});
            }
        }
    }
    return ans;
}
