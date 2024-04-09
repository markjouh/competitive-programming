// Doubly linked list with the position as the data field. Used to represent a grouping and ordering of a permutation.
// Incomplete, will probably add more helper functions as I need them

struct chain {
    int n;
    vector<array<int, 2>> ch;
 
    chain(int _n) : n(_n) {
        ch.resize(n, {-1, -1});
    }
 
    void insert_l(int x, int y) {
        assert(x != y);
        if (ch[y][0] == -1) {
            ch[y][0] = x;
            ch[x][1] = y;
            return;
        }
        ch[ch[y][0]][1] = x;
        ch[x][0] = ch[y][0];
        ch[x][1] = y;
        ch[y][0] = x;
    }
 
    void insert_r(int x, int y) {
        assert(x != y);
        if (ch[y][1] == -1) {
            ch[y][1] = x;
            ch[x][0] = y;
            return;
        }
        ch[ch[y][1]][0] = x;
        ch[x][1] = ch[y][1];
        ch[x][0] = y;
        ch[y][1] = x;
    }
 
    vector<int> recover() {
        vector<bool> vis(n);
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && ch[i][0] == -1) {
                int x = i;
                while (x != -1) {
                    res.push_back(x);
                    vis[x] = true;
                    x = ch[x][1];
                }
            }
        }
        return res;
    }
};
