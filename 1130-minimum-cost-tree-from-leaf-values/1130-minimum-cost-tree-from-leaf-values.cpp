#include <algorithm>
#include <stack>
#include <vector>

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        st.push(INT_MAX);
        int result = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() <= arr[i]) {
                int cur = st.top();
                st.pop();
                result += cur *min(st.top(), arr[i]);
            }
            st.push(arr[i]);
        }
        
        while (st.size() > 2) {
            int cur = st.top();
            st.pop();
            result += cur*st.top();
        }
        return result;
    }
};
