struct adj_xor {
    multiset<pair<int, int>> vals;
    map<int, int> xors;
 
    void add(pair<int, int> v) {
        vals.insert(v);
        auto it = vals.find(v);
        if (it != vals.begin()) {
            xors[v.first ^ (*prev(it)).first]++;
        }
        if (it != prev(vals.end())) {
            xors[v.first ^ (*next(it)).first]++;
        }
        if (it != vals.begin() && it != prev(vals.end())) {
            xors[(*prev(it)).first ^ (*next(it)).first]--;
        }
    }
 
    void remove(pair<int, int> v) {
        auto it = vals.find(v);
        if (it != vals.begin()) {
            xors[v.first ^ (*prev(it)).first]--;
        }
        if (it != prev(vals.end())) {
            xors[v.first ^ (*next(it)).first]--;
        }
        if (it != vals.begin() && it != prev(vals.end())) {
            xors[(*prev(it)).first ^ (*next(it)).first]++;
        }
        vals.erase(it);
    }
 
    int get_min() {
        while (!xors.empty() && xors.begin()->second == 0) {
            xors.erase(xors.begin());
        }
        return xors.empty() ? INT_MAX : xors.begin()->first;
    }
};
