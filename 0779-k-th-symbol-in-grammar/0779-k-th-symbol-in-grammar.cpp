class Solution {
public:
    int kthGrammar(int n, int k) {
        stack<char> st;
        int depth = n;
        int kc = k;
        while (depth != 1) {
            if (kc & 1) {
                st.push('f');
            } else {
                st.push('s');
            }
            
            kc = ((kc/2) + (kc % 2));
            depth--;
        }
        
        int val = 0;
        
        while (!st.empty()) {
            if (st.top() == 'f') {
                if (val == 0) {
                    val = 0;
                } else {
                    val = 1;
                }
            } else {
                if (val == 0) {
                    val = 1;
                } else {
                    val = 0;
                }
            }
            st.pop();
        }
        
        return val;
    }
};