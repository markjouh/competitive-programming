// https://rng-58.blogspot.com/2017/02/hashing-and-probability-of-collision.html
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int64_t MOD = (1LL << 61) - 1;
const int64_t B = uniform_int_distribution<int64_t>(1E3, MOD - 1E3)(rng);

vector<int64_t> pow_b = {1};

struct hash_item {
    int64_t value;
    int len;

    hash_item(int64_t x, int y) : value(x), len(y) {}

    hash_item operator+(hash_item b) {
        return hash_item((__int128_t(value) * pow_b[b.len] + b.value) % MOD, len + b.len);
    }

    bool operator==(hash_item b) {
        return value == b.value && len == b.len;
    }
};

template<class T>
struct rolling_hash {
    vector<int64_t> hash;

    rolling_hash(T s) {
        hash.resize(int(s.size()) + 1);
        for (int i = 0; i < int(s.size()); i++) {
            hash[i + 1] = (__int128_t(hash[i]) * B + s[i]) % MOD;
        }
        while (int(pow_b.size()) < int(hash.size())) {
            pow_b.push_back(__int128_t(pow_b.back()) * B % MOD);
        }
    }

    hash_item get_hash(int l, int r) {
        return hash_item(((hash[r] - __int128_t(hash[l]) * pow_b[r - l]) % MOD + MOD) % MOD, r - l);
    }

    hash_item get_hash() {
        return get_hash(0, int(hash.size()) - 1);
    }
};
