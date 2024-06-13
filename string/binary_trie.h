struct binary_trie {
    struct node {
        int nxt[2];
        int cnt = 0;
 
        node() {
            nxt[0] = nxt[1] = -1;
        }
    };
 
    vector<node> trie;
 
    binary_trie() : trie(1) {}
 
    void add(int val, int amt = 1) {
        int x = 0;
        for (int i = 30; i >= 0; i--) {
            bool d = (val >> i) & 1;
            if (trie[x].nxt[d] == -1) {
                trie[x].nxt[d] = int(trie.size());
                trie.emplace_back();
            }
            x = trie[x].nxt[d];
            trie[x].cnt += amt;
        }
    }
 
    int max_xor(int val) {
        int x = 0, res = 0;
        for (int i = 30; i >= 0; i--) {
            bool d = (val >> i) & 1;
            if (trie[x].nxt[1 - d] != -1 && trie[trie[x].nxt[1 - d]].cnt > 0) {
                x = trie[x].nxt[1 - d];
                res |= 1 << i;
            } else if (trie[x].nxt[d] != -1 && trie[trie[x].nxt[d]].cnt > 0) {
                x = trie[x].nxt[d];
            } else {
                break;
            }
        }
        return res;
    }
};
