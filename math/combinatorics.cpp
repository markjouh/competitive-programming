#include "bits/stdc++.h"

using namespace std;

#define int long long

const int MOD = 998244353;

int exp(int base, int exp) {
  int res = 1;
  while (exp) {
    if (exp & 1) {
      res = (res * base) % MOD;
    }
    exp >>= 1;
    base = (base * base) % MOD;
  }
  return res;
}

vector<int> fact, inv_fact;

int mod_inv(int base) {
  return exp(base, MOD - 2);
}

void precalc(int n) {
  fact.resize(n + 1);
  inv_fact.resize(n + 1);
  fact[0] = fact[1] = inv_fact[0] = inv_fact[1] = 1;
  for (int i = 2; i <= n; i++) {
    fact[i] = (i * fact[i - 1]) % MOD;
  }
  inv_fact[n] = mod_inv(fact[n]);
  for (int i = n - 1; i >= 2; i--) {
    inv_fact[i] = ((i + 1) * inv_fact[i + 1]) % MOD;
  }
}

int nck(int n, int k) {
  if (k < 0 || n < k) {
    return 0;
  }
  return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

// Example: CF 1359E
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  precalc(5e5);
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + nck(n / i - 1, k - 1)) % MOD;
  }
  cout << ans << '\n';
}
