// https://judge.yosupo.jp/submission/200809
// https://judge.yosupo.jp/submission/200810

namespace fast_io {
    constexpr int BUF_SZ = 1 << 19;
    constexpr int B = 10000;

    constexpr array<array<char, 5>, B> body = []() {
        array<array<char, 5>, B> ret = {};
        for (int i = 0; i < B; i++) {
            int x = i;
            for (int j = 0; j < 4; j++) {
                ret[i][j] = char('0' + x % 10);
                x /= 10;
            }
        }
        return ret;
    }();

    constexpr array<array<char, 6>, B> tail = []() {
        array<array<char, 6>, B> ret = {};
        char buf[10] = {};

        for (int i = 0; i < B; i++) {
            int x = i, len = 0;
            while (x >= 10) {
                buf[len++] = char('0' + x % 10);
                x /= 10;
            }
            buf[len++] = char('0' + x);

            for (int j = 0; j < len; j++) {
                ret[i][len - j - 1] = buf[j];
            }
            ret[i][5] = char(len);
        }
        return ret;
    }();

    char buf_in[BUF_SZ], buf_out[BUF_SZ];
    int idx_in = 0, bytes_in = 0, idx_out = 0;

    char read_char() {
        if (idx_in == bytes_in) {
            idx_in = 0;
            bytes_in = int(fread(buf_in, 1, BUF_SZ, stdin));
            if (!bytes_in) {
                return EOF;
            }
        }
        return buf_in[idx_in++];
    }

    void write_char(char c) {
        if (idx_out == BUF_SZ) {
            fwrite(buf_out, 1, BUF_SZ, stdout);
        }
        buf_out[idx_out++] = c;
    }

    string read_string() {
        char c = ' ';
        while ((c = read_char()) < 33);
        string ret(1, c);
        while ((c = read_char()) >= 33) {
            ret += c;
        }
        return ret;
    }

    void write_string(string s) {
        for (int i = 0; i < int(s.size()); i++) {
            write_char(s[i]);
        }
    }

    template<typename T = int>
    T read_num() {
        char c = 0;
        bool neg = false;
        while (!isdigit(c = read_char())) {
            neg |= c == '-';
        }
        T ret = c - '0';
        while (isdigit(c = read_char())) {
            ret = 10 * ret + (c - '0');
        }
        return neg ? -ret : ret;
    }

    template<typename T>
    void write_num(T x) {
        if (x < 0) {
            buf_out[idx_out++] = '-';
            x = -x;
        }
        static char buf[40];
        int len = 0;
        while (x >= B) {
            memcpy(buf + len, body[x % B].begin(), 4);
            len += 4;
            x /= B;
        }
        memcpy(buf_out + idx_out, tail[x].begin(), tail[x][5]);
        idx_out += tail[x][5];
        while (len) {
            buf_out[idx_out++] = buf[--len];
        }
        if (idx_out >= BUF_SZ - 40) {
            fwrite(buf_out, 1, idx_out, stdout);
            idx_out = 0;
        }
    }

    void exit_io() {
        fwrite(buf_out, 1, idx_out, stdout);
    }

    struct init_io {
        init_io() {
            assert(atexit(exit_io) == 0);
        }
    } _init_io;
}
