class MaxStack {
    stack<int> st, maxelements;
public:
    MaxStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if (maxelements.empty() || maxelements.top() <= x) {
            maxelements.push(x);
        }
    }
    
    int pop() {
        int val = st.top();
        st.pop();
        
        if(!maxelements.empty() && maxelements.top() == val) {
            maxelements.pop();
        }
        return val;
    }
    
    int top() {
        return st.top();
    }
    
    int peekMax() {
        return maxelements.top();
    }
    
    int popMax() {
        stack<int> temp;
        int val = maxelements.top();
        maxelements.pop();
        
        while (st.top() != val) {
            temp.push(st.top());
            st.pop();
        }
        
        st.pop();
        
        while (!temp.empty()) {
            this->push(temp.top());
            temp.pop();
        }
        return val;
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