vector<bool> isprime;
vector<ll> primes, mnfactor;

void sieve(long long n) {
    isprime.resize(n + 1);
    fill(all(isprime), 1);
    isprime[0] = isprime[1] = false;
    mnfactor.resize(n + 1);
    // Runs in O(n * log(log(n))).
    for (long long i = 2; i <= n; i++) {
        if (isprime[i]) {
            primes.push_back(i);
            mnfactor[i] = i;
            for (long long j = i * i; j <= n; j += i) {
                if (prime[j]) {
                    isprime[j] = false;
                    mnfactor[j] = i;
                }
            }
        }
    }
}
