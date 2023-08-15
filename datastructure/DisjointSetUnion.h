/**
 * Author: Mark Zhou
 * Date: 15 August 2023
 * Description: Disjoint set union data structure.
 * Verification: https://judge.yosupo.jp/submission/155950
 * Time: O(a(n)) (near constant) queries.
 */

struct DSU {
    vector<int> par, set_sz;

    DSU(int n) : par(n, -1), set_sz(n, 1) {}

    bool same_set(int a, int b) {
        return find(a) == find(b);
    }

    int size(int x) {
        return set_sz[find(x)];
    }

    int find(int x) {
        return par[x] == -1 ? x : par[x] = find(par[x]);
    }

    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) {
            return;
        }
        if (set_sz[a] < set_sz[b]) {
            swap(a, b);
        }
        par[b] = a;
        set_sz[a] += set_sz[b];
    }
};
