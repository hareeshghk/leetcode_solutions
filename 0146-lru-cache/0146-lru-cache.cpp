#include <algorithm>
#include <unordered_map>

class Node {
    shared_ptr<Node> left, right;
    int key, value;
public:
    Node(int k, int v) {
        key = k;
        value = v;
        left = nullptr;
        right = nullptr;
    }
    
    int getKey() {
        return key;
    }
    int getValue() {
        return value;
    }
    
    void setValue(int v) {
        value = v;
    }
    
    void setLeft(shared_ptr<Node> l) {
        left = l;
    }
    
    void setRight(shared_ptr<Node> l) {
        right = l;
    }
    shared_ptr<Node> getLeft() {
        return left;
    }
    
    shared_ptr<Node> getRight() {
        return right;
    }
};

class LRUCache {
    int _capacity;
    unordered_map<int, shared_ptr<Node>> mapper;
    shared_ptr<Node> start, end;
public:
    LRUCache(int capacity) {
        start = make_shared<Node>(-1, -1);
        end = make_shared<Node>(-1, -1);
        start->setRight(end);
        end->setLeft(start);
        _capacity = capacity;
    }
    
    int get(int key) {
        if (mapper.find(key) == mapper.end()) return -1;
        
        auto node = mapper[key];
        pushToTop(node);
        return node->getValue();
    }
    
    void put(int key, int value) {
        if (mapper.find(key) == mapper.end()) {
            // new node.
            auto node = make_shared<Node>(key, value);
            mapper[key] = node;
            addNewNode(node);
            if (mapper.size() > _capacity) {
                removeOldestNode();
            }
        } else {
            auto node = mapper[key];
            node->setValue(value);
            pushToTop(node);
        }
    }
    
private:
    void removeOldestNode() {
        auto nodeToBeRemoved = end->getLeft();
        
        int key = nodeToBeRemoved->getKey();
        mapper.erase(key);
        
        nodeToBeRemoved->getLeft()->setRight(end);
        nodeToBeRemoved->getRight()->setLeft(nodeToBeRemoved->getLeft());
    }
    
    void pushToTop(shared_ptr<Node> node) {
        node->getLeft()->setRight(node->getRight());
        node->getRight()->setLeft(node->getLeft());
        
        node->setRight(start->getRight());
        start->getRight()->setLeft(node);
        node->setLeft(start);
        start->setRight(node);
    }
    
    void addNewNode(shared_ptr<Node> node) {
        node->setRight(start->getRight());
        start->getRight()->setLeft(node);
        node->setLeft(start);
        start->setRight(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
