#include <algorithm>
#include <stack>
#include <string>

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> vals;
        int count = 0;
        for (auto ch : s) {
            if (ch == '(') {
                vals.push(count);
                count = 0;
            } else {
                count = vals.top() + max(2*count,1);
                vals.pop();
            }
        }
        return count;
    }
};
