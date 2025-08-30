#include <algorithm>
#include <set>
#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> values;
        set<string> ops {"+", "-", "*", "/"};
        for (auto x:tokens) {
            if (ops.find(x) != ops.end()) {
                int a,b;
                a = values.top();
                values.pop();
                b = values.top();
                values.pop();
                values.push(evalcase(a,b,x));
            } else {
                values.push(stoi(x));
            }
        }
        return values.top();
    }
    
    int evalcase(int b_val, int a_val, string ch) {
        
        if (ch == "+") {
            return a_val+b_val;
        } else if (ch == "-") {
            return a_val-b_val;
        } else if (ch == "*") {
            return a_val*b_val;
        } else {
            return a_val/b_val;
        }
    }
};
