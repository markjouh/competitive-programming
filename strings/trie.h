struct trie {
    struct node {
        int nxt[26];
        bool flag = false;

        node() {
            memset(nxt, -1, sizeof nxt);
        }
    };

    vector<node> t;

    trie() : t(1) {}

    void add(string &s) {
        int x = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (t[x].nxt[c] == -1) {
                t[x].nxt[c] = sz(t);
                t.emplace_back();
            }
            x = t[x].nxt[c];
        }
        t[x].flag = true;
    }
};
