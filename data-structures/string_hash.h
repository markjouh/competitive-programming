mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const long long MOD = (1ll << 61) - 1;
const long long B = uniform_int_distribution<long long>(1e3, MOD - 1e3)(rng);

vector<long long> pow_b = {1};

template <typename T>
struct Hash {
    T s;
    vector<long long> h;

    Hash(T _s) : s(_s) {
        h.resize(sz(s) + 1);
        for (int i = 0; i < sz(s); i++) {
            h[i + 1] = (__int128_t(h[i]) * B + s[i]) % MOD;
        }
        while (pow_b.size() < h.size()) {
            pow_b.push_back(__int128_t(pow_b.back()) * B % MOD);
        }
    }

    long long get_hash(int l, int r) {
        return ((h[r] - __int128_t(h[l]) * pow_b[r - l]) % MOD + MOD) % MOD;
    };
};
