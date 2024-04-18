struct mint {
    int v;
    static const int MOD = 1e9 + 7; // 998244353

    mint(long long _v = 0) {
        v = (-MOD < _v && _v < MOD ? _v : _v % MOD);
        if (v < 0) {
            v += MOD;
        }
    }

    friend mint pow(mint base, int exp) {
        mint res = 1;
        while (exp) {
            if (exp & 1) {
                res *= base;
            }
            base *= base;
            exp >>= 1;
        }
        return res;
    }

    mint &operator+=(mint b) {
        if ((v += b.v) >= MOD) {
            v -= MOD;
        }
        return *this;
    }

    mint &operator-=(mint b) {
        if ((v -= b.v) < 0) {
            v += MOD;
        }
        return *this;
    }

    mint &operator*=(mint b) {
        v = 1ll * v * b.v % MOD;
        return *this;
    }

    mint &operator/=(mint b) {
        v = 1ll * v * pow(b, MOD - 2).v % MOD;
        return *this;
    }

    friend mint operator+(mint a, mint b) {
        return a += b;
    }

    friend mint operator-(mint a, mint b) {
        return a -= b;
    }

    friend mint operator*(mint a, mint b) {
        return a *= b;
    }

    friend mint operator/(mint a, mint b) {
        return a /= b;
    }
    
    friend istream &operator>>(istream &is, mint a) {
        long long x;
        is >> x;
        a = mint(x);
        return is;
    }

    friend ostream &operator<<(ostream &os, mint a) {
        return os << a.v;
    }
};
