/**
 * Description: Helper functions for modular arithmetic and combinatorics.
 * Verification: https://codeforces.com/contest/1794/submission/219590239
 */

long long mod_exp(long long base, int exp) {
    long long res = 1;
    while (exp != 0) {
        if (exp & 1) {
            res = res * base % MOD;
        }
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

long long mod_inv(int x) {
    return mod_exp(x, MOD - 2);
}

vector<long long> fact, inv_fact;

void gen_factorial(int n) {
    fact.resize(n + 1);
    inv_fact.resize(n + 1);
    fact[0] = fact[1] = inv_fact[0] = inv_fact[1] = 1;

    for (int i = 2; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    inv_fact[n] = mod_inv(fact[n]);
    for (int i = n - 1; i >= 2; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }
}

long long choose(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}