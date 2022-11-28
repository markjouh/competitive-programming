struct DSU {
  vector<int> siz, par;

  void init(int n) {
    siz.resize(n, 1);
    par.resize(n, -1);`
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
    if (siz[a] < siz[b]) {
      swap(a, b);
    }
    par[b] = a;
    siz[a] += siz[b];
  }
}
