struct Mint {
    int v;
    static const int MOD = 1e9 + 7;

    Mint(long long _v = 0) {
        v = (-MOD < _v && _v < MOD ? _v : _v % MOD);
        if (v < 0) {
            v += MOD;
        }
    }

    friend Mint pow(Mint base, int exp) {
        Mint res = 1;
        while (exp) {
            if (exp & 1) {
                res *= base;
            }
            base *= base;
            exp >>= 1;
        }
        return res;
    }

    Mint &operator+=(Mint b) { if ((v += b.v) >= MOD) v -= MOD; return *this; }
    Mint &operator-=(Mint b) { if ((v -= b.v) < 0) v += MOD; return *this; }
    Mint &operator*=(Mint b) { v = (long long) v * b.v % MOD; return *this; }
    Mint &operator/=(Mint b) { v = (long long) v * pow(b, MOD - 2).v % MOD; return *this; }

    friend Mint operator+(Mint a, Mint b) { return a += b; }
    friend Mint operator-(Mint a, Mint b) { return a -= b; }
    friend Mint operator*(Mint a, Mint b) { return a *= b; }
    friend Mint operator/(Mint a, Mint b) { return a /= b; }
};
