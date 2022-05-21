class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> freq;
        
        st.push("");
        
        int idx = 0, n = s.length();
        
        while (idx < n) {
            if (s[idx] == '[') {
                st.push("");
                idx++;
                continue;
            } else if (s[idx] ==']') {
                auto num = freq.top();freq.pop();
                auto str = st.top();st.pop();
                
                auto res = ReplicateString(str, num);
                
                str = st.top(); st.pop();
                
                st.push(str+res);
                ++idx;
                continue;
            } else if (isalpha(s[idx])) {
                string curstring = "";
                while (idx < n && isalpha(s[idx])) {
                    curstring += s[idx];
                    idx++;
                }
                
                auto str = st.top(); st.pop();
                
                st.push(str+curstring);
                continue;
            } else {
                string curstring = "";
                while (idx < n && isdigit(s[idx])) {
                    curstring += s[idx];
                    idx++;
                }
                freq.push(stoi(curstring));
                continue;
            }
        }
        
        if (st.empty()) return "";
        
        return st.top();
    }
    
    string ReplicateString(string s, int k) {
        string result = "";
        
        while (k!=0) {
            if (k&1) {
                result += s;
            }
            k>>=1;
            s +=s;
        }
        return result;
    }
};