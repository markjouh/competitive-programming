#include "bits/stdc++.h"

using namespace std;

#define int int64_t

int tree_sz;
vector<int> tree;

void update(int i, int v, int x = 0, int tl = 0, int tr = tree_sz) {
  if (tl + 1 == tr) {
    tree[x] = v;
    return;
  }
  int mid = tl + (tr - tl) / 2;
  if (i < mid) {
    update(i, v, 2 * x + 1, tl, mid);
  } else {
    update(i, v, 2 * x + 2, mid, tr);
  }
}

void build(vector<int> &a, int x = 0, int tl = 0, int tr = tree_sz) {
  if (tl + 1 == tr) {
    if (tl < (int)a.size()) {
      tree[x] = a[tl];
    }
    return;
  }
  int mid = tl + (tr - tl) / 2;
  build(a, 2 * x + 1, tl, mid);
  build(a, 2 * x + 2, mid, tr);
  tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
}

int query(int l, int r, int x = 0, int tl = 0, int tr = tree_sz) {
  if (l >= tr || r <= tl) {
    return 0;
  }
  if (l >= tl && r <= tr) {
    return tree[x];
  }
  int mid = tl + (tr - tl) / 2;
  return query(l, r, 2 * x + 1, tl, mid) + query(l, r, 2 * x + 2, mid, tr);
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  const int N = 1e6; // whatever size you need

  tree_sz = 1;
  while (tree_sz * tree_sz < N) {
    tree_sz *= 2;
  }
  tree.resize(2 * tree_sz);
}
