namespace modular {
    const int MOD = 998244353;

    int madd(int a, int b) {
        return (0ll + a + b) % MOD;
    }

    int msub(int a, int b) {
        return ((0ll + a - b) % MOD + MOD) % MOD;
    }

    int mmul(int a, int b) {
        return 1ll * a * b % MOD;
    }

    int mpow(int base, int exp) {
        int res = 1;
        while (exp) {
            if (exp & 1) {
                res = mmul(res, base);
            }
            exp >>= 1;
            base = mmul(base, MOD);
        }
        return res;
    }

    int minv(int base) {
        return mpow(base, MOD - 2);
    }

    int mdiv(int a, int b) {
        return mmul(a, minv(b));
    }

    vector<int> fact, inv_fact;

    void gen_factorial(int n) {
        fact.resize(n + 1);
        inv_fact.resize(n + 1);
        fact[0] = fact[1] = inv_fact[0] = inv_fact[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            fact[i] = mmul(fact[i - 1], i);
        }

        inv_fact[n] = minv(fact[n]);
        for (int i = n - 1; i >= 2; i--) {
            inv_fact[i] = mmul(inv_fact[i + 1], i + 1);
        }
    }

    int nck(int n, int k) {
        return k < 0 || k > n ? 0 : mdiv(fact[n], mmul(fact[k], fact[n - k]));
    }
};
