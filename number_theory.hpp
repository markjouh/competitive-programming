namespace number_theory {
    vector<int> mn_factor;
    vector<bool> prime;
    vector<int> primes;

    void sieve(int n) {
        mn_factor.resize(n + 1);
        prime.resize(n + 1, true);
        prime[0] = prime[1] = false;

        for (int i = 2; i <= n; i++) {
            if (prime[i]) {
                mn_factor[i] = i;
                primes.push_back(i);

                for (long long j = 1ll * i * i; j <= n; j += i) {
                    if (prime[j]) {
                        prime[j] = false;
                        mn_factor[j] = i;
                    }
                }
            }
        }
    }

    vector<pair<int, int>> factorize(int n) {
        vector<pair<int, int>> res;

        if (n <= mn_factor.size()) {
            while (n != 1) {
                if (res.empty() || res.back().first != mn_factor[n]) {
                    res.push_back({mn_factor[n], 0});
                }
                n /= mn_factor[n];
                res.back().second++;
            }
            return res;
        }

        for (int p : primes) {
            if (1ll * p * p > n) {
                break;
            }
            if (n % p == 0) {
                res.push_back({p, 0});
                while (n % p == 0) {
                    n /= p;
                    res.back().second++;
                }
            }
        }
        if (n > 1) {
            res.push_back({n, 1});
        }
        return res;
    }

    vector<int> get_factors(int n) {
        vector<int> res;
        res.push_back(1);
        for (auto [base, exp] : factorize(n)) {
            int old_sz = res.size();
            int cur = 1;
            for (int i = 0; i < exp; i++) {
                cur *= base;
                for (int j = 0; j < old_sz; j++) {
                    res.push_back(res[j] * cur);
                }
            }
        }
        return res;
    }
};
