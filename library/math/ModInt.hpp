template<int MOD>
struct ModInt {
    int v;
 
    ModInt(long long _v = 0) {
        v = (-MOD < _v && _v < MOD ? _v : _v % MOD);
        if (v < 0) {
            v += MOD;
        }
    }
 
    friend ModInt pow(ModInt base, int exp) {
        ModInt res = 1;
        while (exp) {
            if (exp & 1) {
                res *= base;
            }
            base *= base;
            exp >>= 1;
        }
        return res;
    }
 
    ModInt &operator+=(ModInt b) {
        if ((v += b.v) >= MOD) {
            v -= MOD;
        }
        return *this;
    }
 
    ModInt &operator-=(ModInt b) {
        if ((v -= b.v) < 0) {
            v += MOD;
        }
        return *this;
    }
 
    ModInt &operator*=(ModInt b) {
        v = 1ll * v * b.v % MOD;
        return *this;
    }
 
    ModInt &operator/=(ModInt b) {
        v = 1ll * v * pow(b, MOD - 2).v % MOD;
        return *this;
    }
 
    friend ModInt operator+(ModInt a, ModInt b) {
        return a += b;
    }
 
    friend ModInt operator-(ModInt a, ModInt b) {
        return a -= b;
    }
 
    friend ModInt operator*(ModInt a, ModInt b) {
        return a *= b;
    }
 
    friend ModInt operator/(ModInt a, ModInt b) {
        return a /= b;
    }
    
    friend istream &operator>>(istream &is, ModInt a) {
        long long x;
        is >> x;
        a = ModInt(x);
        return is;
    }
 
    friend ostream &operator<<(ostream &os, ModInt a) {
        return os << a.v;
    }
};
