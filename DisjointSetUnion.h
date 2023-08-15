/**
 * Author: Mark Zhou
 * Date: 15 August 2023
 * Description: Disjoint set union data structure.
 * Verification: https://judge.yosupo.jp/submission/155950
 * Time: O(a(n)) (near constant) queries.
 */

struct DSU {
    vector<int> par, comp_sz;

    DSU(int n) : par(n, -1), comp_sz(n, 1) {}

    bool same_set(int a, int b) {
        return find(a) == find(b);
    }

    int size(int x) {
        return comp_sz[find(x)];
    }

    int find(int x) {
        return par[x] == -1 ? x : par[x] = find(par[x]);
    }

    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) {
            return;
        }
        if (comp_sz[a] < comp_sz[b]) {
            swap(a, b);
        }
        par[b] = a;
        comp_sz[a] += comp_sz[b];
    }
};
