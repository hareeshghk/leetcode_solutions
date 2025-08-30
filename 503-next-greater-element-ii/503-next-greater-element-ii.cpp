#include <stack>
#include <vector>

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> result(n, -1);
        
        for (int i = 2*n-1; i >=0; i--) {
            while (!st.empty() && st.top() <= nums[i%n]) {
                st.pop();
            }
            
            if (i < n) {
                if (!st.empty()) {
                    result[i] = st.top();
                } else {
                    result[i] = -1;
                }
            }
                
            st.push(nums[i%n]);
        }
        
//         for (int i = 0; i < n; ++i) {
//             while (!st.empty() && nums[st.top()] < nums[i]) {
//                 result[st.top()] = nums[i];
//                 st.pop();
//             }
//             st.push(i);
//         }
        
//         for (int i = 0; i < n; ++i) {
//             while (!st.empty() && nums[st.top()] < nums[i]) {
//                 result[st.top()] = nums[i];
//                 st.pop();
//             }
//             st.push(i);
//         }
        return result;
    }
};
