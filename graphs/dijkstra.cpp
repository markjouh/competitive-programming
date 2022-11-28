int dijkstra(vector<vector<pii>> g) {
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
    return cost[n - 1];
}
