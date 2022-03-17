class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> input;
        stack<pair<int,int>> count;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] =='(') {
                input.push(i);
            } else {
                int top = input.top();
                input.pop();
                if (count.empty()) {
                    count.push(make_pair(top, 1));
                } else {
                    int prevvalue = 0;
                    while (!count.empty()) {
                        if (count.top().first > top) {
                            prevvalue += count.top().second;
                            count.pop();
                        } else {
                            break;
                        }
                    }
                    if (prevvalue == 0) {
                        count.push(make_pair(top, 1));
                    } else {
                        count.push(make_pair(top, 2*prevvalue));
                    }
                }
            }
        }
        
        int ans = 0;
        while (!count.empty()) {
            ans += count.top().second;
            count.pop();
        }
        return ans;
    }
};