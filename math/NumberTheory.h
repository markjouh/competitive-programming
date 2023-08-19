/**
 * Description: Sieve and other helper functions for number theory problems.
 * Verification: https://codeforces.com/contest/1794/submission/219590239
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

            for (ll i = 1ll * p * p; i <= n; i += p) {
                if (prime[i]) {
                    prime[i] = false;
                    mn_factor[i] = p;
                }
            }
        }
    }
}