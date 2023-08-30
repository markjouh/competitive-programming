/**
 * Description: Sieve and other helper functions for number theory problems.
 * Verification: https://codeforces.com/contest/1673/submission/219621655
 */

vector<int> mn_factor;
vector<bool> prime;
vector<int> primes;

void sieve(int n) {
    mn_factor.assign(n + 1, 0);
    prime.assign(n + 1, true);
    prime[0] = prime[1] = false;
    primes.clear();

    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            mn_factor[p] = p;
            primes.push_back(p);

            for (long long i = 1ll * p * p; i <= n; i += p) {
                if (prime[i]) {
                    prime[i] = false;
                    mn_factor[i] = p;
                }
            }
        }
    }
}

vector<pair<int, int>> prime_factorize(int n) {
    vector<pair<int, int>> res;
    for (int p : primes) {
        if (1ll * p * p > n) {
            break;
        }
        if (n % p == 0) {
            res.push_back({p, 0});
            do {
                n /= p;
                res.back().second++;
            } while (n % p == 0);
        }
    }
    if (n > 1) {
        res.push_back({n, 1});
    }
    return res;
}

vector<int> get_factors(int n) {
    vector<int> res = {1};
    for (auto [p, exp] : prime_factorize(n)) {
        const int prev_sz = res.size();
        int mul = 1;
        for (int i = 0; i < exp; i++) {
            mul *= p;
            for (int j = 0; j < prev_sz; j++) {
                res.push_back(res[j] * mul);
            }
        }
    }
    return res;
}