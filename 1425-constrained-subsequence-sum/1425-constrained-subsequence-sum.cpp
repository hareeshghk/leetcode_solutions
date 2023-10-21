class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp = vector<int>(n, 0);
        
        deque<int> prevStore = deque<int>();
        int answer = nums[0];
        for (int i = 0; i < n; ++i) {
            while (!prevStore.empty()) {
                if (prevStore.front() < i-k) {
                    prevStore.pop_front();
                } else {
                    break;
                }
            }
            
            int prevMax = prevStore.empty()?0:dp[prevStore.front()];
            
            dp[i] = max(nums[i], nums[i]+prevMax);
            answer = max(answer, dp[i]);
            while (!prevStore.empty() && dp[prevStore.back()] <= dp[i]) {
                prevStore.pop_back();
            }
            
            prevStore.push_back(i);
        }
        return answer;
    }
};