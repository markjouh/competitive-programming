void dijkstra() {
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    // O(E * log(V))
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> cost(n, 1e9);
    pq.push({0, 0});
    cost[0] = 0;
    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        for (auto [v, edge_w] : g[u]) {
            if (w + edge_w < cost[v]) {
                cost[v] = w + edge_w;
                pq.push({cost[v], v});
            }
        }
    }
    cout << cost[n - 1] << '\n';
}
