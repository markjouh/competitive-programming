namespace combo {
    vector<mint> fact, inv_fact;

    void gen_fact(int n) {
        fact.resize(n + 1);
        inv_fact.resize(n + 1);
        fact[0] = fact[1] = inv_fact[0] = inv_fact[1] = 1;
        for (int i = 2; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }
        inv_fact[n] = 1 / fact[n];
        for (int i = n - 1; i >= 2; i--) {
            inv_fact[i] = inv_fact[i + 1] * (i + 1);
        }
    }

    mint nck(int n, int k) {
        if (n < k || k < 0) {
            return 0;
        }
        return fact[n] * inv_fact[k] * inv_fact[n - k];
    }
};
