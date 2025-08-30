#include <queue>

class MyStack {
    queue<int> q1,q2;
    int turn;
public:
    MyStack() {
        turn = 1;
    }
    
    void push(int x) {
        if (turn == 1) {
            q2.push(x);
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
        } else {
            q1.push(x);
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
        turn = 3-turn;
    }
    
    int pop() {
        if (turn == 1) {
            int val = q1.front();
            q1.pop();
            return val;
        } else {
            int val = q2.front();
            q2.pop();
            return val;
        }
    }
    
    int top() {
        if (turn == 1) {
            if (!q1.empty()) return q1.front();
        } else {
            if (!q2.empty()) return q2.front();
        }
        return -1;
    }
    
    bool empty() {
        if (turn == 1) return q1.empty();
        return q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
