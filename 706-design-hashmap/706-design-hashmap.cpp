class MyHashMap {
    vector<vector<pair<int,int>>> hasher;
    int mods;
public:
    MyHashMap() {
        mods = 97;
        hasher.resize(mods, vector<pair<int,int>>());
    }
    
    void put(int key, int value) {
        int hash_val = key%mods;

        for (auto& p : hasher[hash_val]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        hasher[hash_val].push_back(pair<int,int>(key, value));
    }
    
    int get(int key) {
        int hash_val = key%mods;

        for (auto& p : hasher[hash_val]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int hash_val = key%mods;

        for (int i = 0; i < hasher[hash_val].size(); ++i) {
            if (hasher[hash_val][i].first == key) {
                hasher[hash_val].erase(hasher[hash_val].begin()+i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */