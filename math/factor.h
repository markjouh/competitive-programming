namespace factor {
    vector<int> mn_factor, primes;

    void sieve(int n) {
        mn_factor.resize(n + 1);

        for (int i = 2; i <= n; i++) {
            if (!mn_factor[i]) {
                mn_factor[i] = i;
                primes.push_back(i);

                for (long long j = 1LL * i * i; j <= n; j += i) {
                    if (!mn_factor[j]) {
                        mn_factor[j] = i;
                    }
                }
            }
        }
    }

    template<typename T>
    vector<pair<T, int>> factorize(T x) {
        vector<pair<T, int>> res;

        if (x <= int(mn_factor.size()) - 1) {
            while (x > 1) {
                int fac = mn_factor[x];
                int exp = 0;
                while (x % fac == 0) {
                    x /= fac;
                    exp++;
                }
                res.emplace_back(fac, exp);
            }
            return res;
        }

        for (int p : primes) {
            if (1LL * p * p > x) {
                break;
            }

            int exp = 0;
            while (x % p == 0) {
                x /= p;
                exp++;
            }
            if (exp > 0) {
                res.emplace_back(p, exp);
            }
        }
        if (x > 1) {
            res.emplace_back(x, 1);
        }
        return res;
    }

    template<typename T> 
    vector<T> get_divisors(T x) {
        vector<T> res = {1};
        for (auto [fac, exp] : factorize(x)) {
            int before = res.size();
            T mul = 1;
            for (int i = 0; i < exp; i++) {
                mul *= fac;
                for (int j = 0; j < before; j++) {
                    res.push_back(res[j] * mul);
                }
            }
        }
        return res;
    }
};
