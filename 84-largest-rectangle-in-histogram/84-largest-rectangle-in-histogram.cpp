class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (st.empty() || heights[st.top()] <= heights[i]) {
                st.push(i);
            } else {
                while (!st.empty() && heights[st.top()] > heights[i]) {
                    int curtop = st.top();
                    st.pop();
                    ans = max(ans, heights[curtop] * (st.empty()? (i):(i - st.top() - 1)));
                }
                st.push(i);
            }
        }
        
        while (!st.empty()) {
            auto curtop = st.top();
            st.pop();
            ans = max(ans, heights[curtop] * (n - (st.empty()?0:(st.top()+1))));
        }
        
        return ans;
    }
};