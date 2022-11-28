vector<pll> factorize(ll n) {
    vector<pll> res;
    // O(log(n)) if we've run sieve up to n.
    if (n <= sz(isprime) - 1) {
        while (n != 1) {
            ll f = mnfactor[n];
            ll exp = 0;
            while (n % f == 0) {
                n /= f;
                exp++;
            }
            res.push_back({f, exp});
        }
    }
    // O(sqrt(n) / log(n)) otherwise. Sieve must be run until at least sqrt(n).
    for (ll p : primes) {
        if (p * p > n) {
            break;
        }
        if (n % p == 0) {
            ll exp = 0;
            while (n % p == 0) {
                n /= p;
                exp++;
            }
            res.push_back({p, exp});
        }
    }
    if (n > 1) {
        res.push_back({n, 1});
    }
    return res;
}
