struct DSU {
  vector<int> sz, par;

  void init(int n) {
    sz.resize(n, 1);
    par.resize(n, -1);
  }

  int get_root(int u) {
    if (par[u] == -1) {
      return u;
    }
    return par[u] = get_root(par[u]);
  }
  
  void unite(int a, int b) {
    a = get_root(a);
    b = get_root(b);
    if (a == b) {
      return;
    }
    if (sz[a] < sz[b]) {
      swap(a, b);
    }
    par[b] = a;
    sz[a] += sz[b];
  }
}
