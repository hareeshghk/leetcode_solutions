class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums2, vector<int>& nums1) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> result(n);
        stack<int> st;
        unordered_map<int,int> mapper;
        for (int i = m-1; i >=0; i--) {
            while (!st.empty() && st.top() <= nums1[i]) {
                st.pop();
            }
            if (st.empty()) {
                mapper[nums1[i]] = -1;
            } else {
                mapper[nums1[i]] = st.top();
            }
            st.push(nums1[i]);
        }
        
        for (int i = 0; i < n; i++) {
            result[i] = mapper[nums2[i]];
        }
        return result;
    }
};