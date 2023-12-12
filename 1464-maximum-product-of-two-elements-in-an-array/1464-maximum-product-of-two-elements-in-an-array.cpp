class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto pq = priority_queue<int, vector<int>, greater<int>>();
        
        for (int i = 0; i < nums.size(); ++i) {
            if (pq.size() < 2) {
                pq.push(nums[i]);
            } else if (pq.top() < nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        int a = pq.top()-1;
        pq.pop();
        int b = pq.top()-1;
        return a*b;
    }
};