class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        // create a function to getnumber of element less than or equal to a value.
        // fn(upper) - fn(lower-1) is the answer.
        return getNumberOfPairsWithMaxSumLimit(upper, nums) - getNumberOfPairsWithMaxSumLimit(lower-1, nums); 
    }
private:
    long long getNumberOfPairsWithMaxSumLimit(int limit, vector<int>& nums) {
        long long answer = 0;
        int n = nums.size();
        int left = 0, right = n-1;
        while (left < right) {
            // since possibleright + nums[left] <= limit
            int limitOfOtherElement = limit-nums[left];
            while (left < right && nums[right] > limitOfOtherElement) {
                right--;
            }
            answer += (right-left);
            left++;
        }
        return answer;
    }
};