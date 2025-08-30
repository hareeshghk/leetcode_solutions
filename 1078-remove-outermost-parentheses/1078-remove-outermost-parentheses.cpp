#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();

        string answer = "";
        int depth = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                if (depth != 0) {
                    answer += '(';
                }

                depth++;
            } else {
                depth--;
                if (depth != 0) {
                    answer += ')';
                }
            }
        }
        return answer;
    }
};
