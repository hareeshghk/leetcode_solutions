class MyListNode {
public:
    MyListNode *prev, *next;
    int data, key;
    MyListNode(int k, int val) {
        data = val;
        key = k;
        prev = nullptr;
        next = nullptr;
    }
    
    void resetPointers() {
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
    MyListNode *head, *tail;
    unordered_map<int, MyListNode*> cache;
    int capacity;
    int cursize;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        cursize = 0;
        head = new MyListNode(-1,-1);
        tail = new MyListNode(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void addNodeToFront(MyListNode *node) {
        node->resetPointers();
        auto temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }
    
    int removeNodeFromLast() {
        auto temp = tail->prev;
        temp->prev->next = tail;
        tail->prev = temp->prev;
        temp->resetPointers();
        return temp->key;
    }
    
    void removeNode(MyListNode *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->resetPointers();
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        
        auto node = cache[key];
        
        removeNode(node);
        addNodeToFront(node);
        return node->data;
    }
    
    void put(int key, int value) {
        if (cache.find(key) == cache.end()) {
            auto node = new MyListNode(key, value);
            cache[key] = node;
            
            addNodeToFront(node);
            ++cursize;
            if (cursize > capacity) {
                cache.erase(removeNodeFromLast());
                --cursize;
            }
        } else {
            auto node = cache[key];
            removeNode(node);
            node->data = value;
            addNodeToFront(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */