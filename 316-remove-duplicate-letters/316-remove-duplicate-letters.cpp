class Solution {
public:
    string result;
    string removeDuplicateLetters(string s) {
        result = "";
        stack<char> st;
        unordered_map<char, int> lastoccurrence;
        unordered_set<char> seen;
        for (int i = 0; i < s.length(); ++i) {
            lastoccurrence[s[i]] = i;
        }
        
        for (int i = 0;i < s.length(); i++) {
            if (seen.find(s[i]) == seen.end()) {
                while (!st.empty() && st.top() > s[i] && lastoccurrence[st.top()] > i) {
                    seen.erase(st.top());
                    st.pop();
                }
                seen.insert(s[i]);
                st.push(s[i]);
            }
        }
        
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};