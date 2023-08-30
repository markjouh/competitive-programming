/**
 * Description: Finds a topological ordering of a digraph.
 * The size of the result will be < n if (and only if) there is a cycle.
 * Verification: https://vjudge.net/solution/44887606/y02y5gOSgTP7p0SgaFgf
 */

vector<int> topsort(vector<vector<int>> &g) {
    const int n = size(g);
    
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

    vector<int> result;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        for (int v : g[u]) {
            if (--in[v] == 0) {
                q.push(v);
            }
        }
    }
    return result;
}