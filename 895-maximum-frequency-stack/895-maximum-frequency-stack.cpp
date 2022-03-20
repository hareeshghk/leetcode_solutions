class Node {
public:
    int key;
    int freq;
    Node* left;
    Node* right;
    Node(int val) {
        key = val;
        freq = 1;
        left = nullptr;
        right = nullptr;
    }
    
    void increment() {
        ++freq;
    }
};

class listObj {
public:
    Node* head;
    Node* tail;
    listObj() {
        head = new Node(-1);
        tail = new Node(-1);
        head->right = tail;
        tail->left = head;
    }
    
    void addNode(Node* obj) {
        auto temp = head->right;
        head->right = obj;
        obj->left = head;
        obj->right = temp;
        temp->left = obj;
    }
    
    void addNodetolast(Node* obj) {
        auto temp = tail->left;
        tail->left = obj;
        obj->right = tail;
        obj->left = temp;
        temp->right = obj;
    }
    
    Node* removeNode() {
        auto temp = head->right;
        head->right = temp->right;
        temp->right->left = head;
        return temp;
    }
};

void removeNode(Node *current) {
    auto l = current->left;
    auto r = current->right;
    l->right = r;
    r->left = l;
}

class FreqStack {
    unordered_map<int /*key*/, stack<Node*>> mapper;
    map<int, listObj*> freq_list;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        if (mapper.find(val) == mapper.end()) {
            mapper[val] = stack<Node*>();
            auto newnode = new Node(val);
            
            mapper[val].push(newnode);
            
            if (freq_list.find(1) == freq_list.end()) {
                freq_list[1] = new listObj();
            }
            freq_list[1]->addNode(newnode);
        } else {
            auto current = mapper[val].top();
            auto newnode = new Node(val);
            newnode->freq = current->freq + 1;
            mapper[val].push(newnode);
            if (freq_list.find(newnode->freq) == freq_list.end()) {
                freq_list[newnode->freq] = new listObj();
            }
            freq_list[newnode->freq]->addNode(newnode);
        }
    }
    
    int pop() {
        auto top = freq_list.rbegin();
        auto cur = top->second->removeNode();
        if (top->second->head->right == top->second->tail) {
            freq_list.erase(top->first);
        }
        
        mapper[cur->key].pop();
        if (mapper[cur->key].empty()) mapper.erase(cur->key);
        int result = cur->key;
        delete cur;
        return result;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */