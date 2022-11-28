// needs sieve

bool ckprime(ll n) {
    // O(1) if we've run sieve up to n.
    if (n <= sz(isprime) - 1) {
        return isprime[n];
    }
    // O(sqrt(n) / log(n)) otherwise. Sieve must be run until at least sqrt(n).
    for (ll p : primes) {
        if (p * p > n) {
            break;
        }
        if (n % p == 0) {
            return false;
        }
    }
    return true;
}
