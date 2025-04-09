class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int minelement = nums[0];
        unordered_set<int> st;

        for (auto num :nums) {
            minelement = min(minelement, num);
            st.insert(num);
        }

        if (minelement < k) return -1;
        int distinctCount = st.size();

        if (minelement == k) return distinctCount-1;
        return distinctCount;
    }
};