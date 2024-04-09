namespace combo {
    const int MX = 1e5;

    mint fact[MX + 1], inv_fact[MX + 1];

    void gen_fact() {
        fact[0] = fact[1] = inv_fact[0] = inv_fact[1] = 1;
        for (int i = 2; i <= MX; i++) {
            fact[i] = fact[i - 1] * i;
        }
        inv_fact[MX] = 1 / fact[MX];
        for (int i = MX - 1; i >= 2; i--) {
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
