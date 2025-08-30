#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        unordered_map<char, int> locc;
        for (int i = 0; i < n; ++i) {
            locc[s[i]] = i;
        }
        
        unordered_set<char> seen;
        stack<char> chosen;
        
        for (int i = 0; i < n; i++) {
            if (seen.count(s[i]) == 0) {
                while (!chosen.empty() && chosen.top() > s[i] && locc[chosen.top()]  > i) {
                    seen.erase(chosen.top());
                    chosen.pop();
                }
                
                chosen.push(s[i]);
                seen.insert(s[i]);
            }
        }
        
        string result = "";
        while (!chosen.empty()) {
            result += chosen.top();
            chosen.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
