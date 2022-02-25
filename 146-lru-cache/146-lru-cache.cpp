class cacheNode {
public:
    int key;
    int value;
    cacheNode *left;
    cacheNode *right;
    cacheNode(int key, int value) {
        this->key = key;
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class LRUCache {
    int cap;
    unordered_map<int /*key*/,cacheNode*> cache_key_map;
    cacheNode *head, *tail;
    int cursize;
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new cacheNode(-1, -1);
        tail = new cacheNode(-1, -1);
        head->right = tail;
        tail->left = head;
        cursize = 0;
    }
    
    void addToCache(cacheNode *node) {
        node->right = head->right;
        head->right->left = node;
        head->right = node;
        node->left = head;
    }
    
    void removeFromCache(cacheNode *node) {
        auto prevNode = node->left;
        auto nextNode = node->right;
        
        prevNode->right = nextNode;
        nextNode->left = prevNode;
    }
    
    cacheNode* removeLastofCache() {
        if (cursize == 0) {
            cout << "cache is empty" << endl;
            return nullptr;
        }
        
        auto curNode = tail->left;
        
        curNode->left->right = tail;
        tail->left = curNode->left;
        return curNode;
    }
    
    int get(int key) {
        if (cache_key_map.find(key) == cache_key_map.end()) return -1;
        
        auto temp = cache_key_map[key];
        removeFromCache(temp);
        addToCache(temp);
        return temp->value;
    }
    
    void put(int key, int value) {
        if (cache_key_map.find(key) != cache_key_map.end()) {
            auto temp = cache_key_map[key];
            removeFromCache(temp);
            temp->value = value;
            addToCache(temp);
        } else {
            auto temp = new cacheNode(key, value);
            addToCache(temp);
            cache_key_map[key] = temp;
            cursize++;
        }
        
        if (cursize > cap) {
            auto removedNode = removeLastofCache();
            if (removedNode == nullptr) return;
            cache_key_map.erase(removedNode->key);
            delete removedNode;
            cursize--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */