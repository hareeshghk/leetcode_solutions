class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> nearestMinLeft(n, -1);
        vector<int> nearestMinRight(n, -1);
        vector<long long> prefixSums(n, 0);
        
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                nearestMinLeft[i] = -1;
            } else {
                nearestMinLeft[i] = st.top();
            }
            st.push(i);
        }
        
        while (!st.empty()) st.pop();
        
        for (int i = n-1; i >=0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                nearestMinRight[i] = n;
            } else {
                nearestMinRight[i] = st.top();
            }
            st.push(i);
        }
        
        long long result = 0;
        int mod = 1000000007;
        prefixSums[0] = nums[0];
        for (int i =1; i < n; i++) {
            prefixSums[i] = prefixSums[i-1] + nums[i];
        }
        
        for (int i = 0; i < n; i++) {
            int left = nearestMinLeft[i] + 1;
            int right = nearestMinRight[i] - 1;
            long long val = (nums[i] * (prefixSums[right]-(left-1>=0?prefixSums[left-1]:0)));
            result = max(result, val);
        }
        return result%mod;
    }
};