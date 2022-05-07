class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        
        if (n < 3) return false;
        
        vector<int> minarray(n);
        minarray[0] = nums[0];
        
        for (int i =1; i < n; i++) {
            minarray[i] = min(minarray[i-1], nums[i]);
        }
        
        stack<int> st;
        
        for (int j = n-1; j>=0;j--) {
            // there is no min to left this means
            if(nums[j]<=minarray[j]) continue;
            
            while (!st.empty() && st.top() <= minarray[j]) {
                st.pop();
            }
            
            if (!st.empty() && st.top() < nums[j]) return true;
            
            st.push(nums[j]);
        }
        return false;
    }
};