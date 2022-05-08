class Bucket;

class Node {
public:
    Node *prev, *next;
    int key, value, freq;
    Bucket* parent;
    Node(int key, int val) :key(key),value(val) {
        prev = nullptr;
        next = nullptr;
        freq = 1;
        parent = nullptr;
    }
};

class Bucket {
public:
    Node *head, *tail;
    int freq, size;
    Bucket *prev, *next;
    Bucket(int f) : freq(f) {
        size = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        prev = nullptr;
        next = nullptr;
    }
    
    void addNode(Node *node) {
        auto temp = head->next;
        head->next  = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
        ++size;
    }
    
    void removeNode(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        --size;
    }
    
    Node* removeFirst() {
        auto temp = tail->prev;
        temp->prev->next = tail;
        tail->prev = temp->prev;
        --size;
        return temp;
    }
};

class LFUCache {
    unordered_map<int, Node*> cache;
    Bucket *head, *tail;
    int capacity, size;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = new Bucket(INT_MAX);
        tail = new Bucket(0);
        head->next = tail;
        tail->prev = head;
    }
    
    void addBucket(Bucket *before, Bucket *after, Bucket *now) {
        before->next = now;
        now->prev = before;
        now->next = after;
        after->prev = now;
    }
    
    void removeBucket(Bucket *bucket) {
        bucket->prev->next = bucket->next;
        bucket->next->prev = bucket->prev;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        
        auto node = cache[key];
        auto bucket = node->parent;
        node->freq++;
        bucket->removeNode(node);
        
        if (bucket->prev->freq == node->freq) {
            node->parent = bucket->prev;
            bucket->prev->addNode(node);
        } else {
            auto newBucket = new Bucket(node->freq);
            addBucket(bucket->prev, bucket, newBucket);
            newBucket->addNode(node);
            node->parent = newBucket;
        }
        
        if (bucket->size == 0) {
            removeBucket(bucket);
        }
        return node->value;
    }
    
    void removeLeastFrequentlyUsed() {
        auto node = tail->prev->removeFirst();
        cache.erase(node->key);
        if (node->parent->size == 0) removeBucket(node->parent);
    }
    
    void updateBucket(Node *node, Bucket *bucket) {
       if (bucket->prev->freq != node->freq) {
           auto newBucket = new Bucket(node->freq);
           addBucket(bucket->prev, bucket, newBucket);
           newBucket->addNode(node);
           node->parent = newBucket;
       } else {
           node->parent = bucket->prev;
           bucket->prev->addNode(node);
       } 
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (cache.find(key) == cache.end()) {
            if (size == capacity) {
                removeLeastFrequentlyUsed();
                --size;
            }
            auto node = new Node(key, value);
            cache[key] = node;
            updateBucket(node, tail);
            ++size;
        } else {
            auto node = cache[key];
            auto bucket = node->parent;
            node->freq++;
            node->value = value;
            bucket->removeNode(node);
            updateBucket(node, bucket);
            if (bucket->size == 0) {
                removeBucket(bucket);
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */