class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        
        pair<long long,long long> cur(0,0), next(0,0);
        
        for (int i = n-1; i >=0; i--) {
            cur.first = max(next.first, next.second+nums[i]);
            cur.second = max(next.second, next.first-nums[i]);
            next = cur;
        }
        return cur.first;
    }
};