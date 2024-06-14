template<int MOD>
struct mod_int {
    int v;
 
    mod_int(long long _v = 0) {
        v = (-MOD < _v && _v < MOD ? _v : _v % MOD);
        if (v < 0) {
            v += MOD;
        }
    }
 
    friend mod_int pow(mod_int base, int exp) {
        mod_int res = 1;
        while (exp) {
            if (exp & 1) {
                res *= base;
            }
            base *= base;
            exp >>= 1;
        }
        return res;
    }
 
    mod_int &operator+=(mod_int b) {
        if ((v += b.v) >= MOD) {
            v -= MOD;
        }
        return *this;
    }
 
    mod_int &operator-=(mod_int b) {
        if ((v -= b.v) < 0) {
            v += MOD;
        }
        return *this;
    }
 
    mod_int &operator*=(mod_int b) {
        v = 1ll * v * b.v % MOD;
        return *this;
    }
 
    mod_int &operator/=(mod_int b) {
        v = 1ll * v * pow(b, MOD - 2).v % MOD;
        return *this;
    }
 
    friend mod_int operator+(mod_int a, mod_int b) {
        return a += b;
    }
 
    friend mod_int operator-(mod_int a, mod_int b) {
        return a -= b;
    }
 
    friend mod_int operator*(mod_int a, mod_int b) {
        return a *= b;
    }
 
    friend mod_int operator/(mod_int a, mod_int b) {
        return a /= b;
    }
    
    friend istream &operator>>(istream &is, mod_int &a) {
        long long x;
        is >> x;
        a = mod_int<MOD>(x);
        return is;
    }
 
    friend ostream &operator<<(ostream &os, mod_int a) {
        return os << a.v;
    }
};

// using mint = mod_int<int(1E9 + 7)>;
// using mint = mod_int<998244353>;
