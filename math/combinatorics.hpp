/**
 * Description: Helper functions for combinatorics problems. Uses ModInt.
 * Verification: https://codeforces.com/contest/1725/submission/220440368
 */

vector<Mint> fact, inv_fact;

void gen_factorial(int n) {
    fact.resize(n + 1);
    inv_fact.resize(n + 1);
    fact[0] = fact[1] = inv_fact[0] = inv_fact[1] = 1;

    for (int i = 2; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }

    inv_fact[n] = fact[n].inv();
    for (int i = n - 1; i >= 2; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1);
    }
}

Mint choose(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    return fact[n] * inv_fact[k] * inv_fact[n - k];
}