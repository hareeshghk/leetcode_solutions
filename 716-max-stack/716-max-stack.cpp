#include <map>
#include <vector>

class Node {
public:
    shared_ptr<Node> prev;
    shared_ptr<Node> next;
    int val;
    Node(int v) {
        val = v;
        prev = nullptr;
        next = nullptr;
    }
};

class MaxStack {
    map<int, vector<shared_ptr<Node>>> maxelements;
    shared_ptr<Node> head,tail;
public:
    MaxStack() {
        head = make_shared<Node>(-1);
        tail = make_shared<Node>(-1);
        head->next = tail;
        tail->prev = head; 
    }
    
    void push(int x) {
        addNode(x);
        if (maxelements.count(x) == 0) {
            maxelements[x] = vector<shared_ptr<Node>>{};
        }
        maxelements[x].push_back(this->getTopPointer());
    }
    
    int pop() {
        int data = this->removeTopVal();
        maxelements[data].pop_back();
        if (maxelements[data].size() == 0) {
            maxelements.erase(data);
        }
        return data;
    }
    
    int top() {
        return getTopVal();
    }
    
    int peekMax() {
        auto &lastVal = *(maxelements.rbegin());
        return lastVal.first;
    }
    
    int popMax() {
        auto &lastVal = *(maxelements.rbegin());
        
        auto node = lastVal.second[lastVal.second.size()-1];
        lastVal.second.pop_back();
        
        int result = lastVal.first;
        // cout << result << endl;
        if (lastVal.second.size() == 0) {
            maxelements.erase(lastVal.first);
        }
        
        removeNode(node);
        

        return result;
    }
    
    void addNode(int val) {
        auto newNode = make_shared<Node>(val);
        
        newNode->next = head->next;
        head->next->prev = newNode;
        head->next = newNode;
        newNode->prev = head;
    }
    
    int getTopVal() {
        return head->next->val;
    }
    
    int removeTopVal() {
        int data = head->next->val;
        removeNode(head->next);
        return data;
    }
    
    void removeNode(shared_ptr<Node> node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    shared_ptr<Node> getTopPointer() {
        return head->next;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
