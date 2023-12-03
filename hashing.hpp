mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int64_t MOD = (1ll << 61) - 1;
const int64_t B = uniform_int_distribution<int64_t>(1e3, MOD - 1e3)(rng);

vector<int64_t> pow_b = {1};

template <typename T>
struct Hash {
    T s;
    vector<int64_t> h;

    Hash(T _s) : s(_s) {
        h.resize(sz(s) + 1);
        for (int i = 0; i < sz(s); i++) {
            h[i + 1] = (__int128_t(h[i]) * B + s[i]) % MOD;
        }
        while (sz(pow_b) < sz(h)) {
            pow_b.pb(__int128_t(pow_b.back()) * B % MOD);
        }
    }

    int64_t get_hash(int l, int r) {
        return ((h[r] - __int128_t(h[l]) * pow_b[r - l]) % MOD + MOD) % MOD;
    };
};
