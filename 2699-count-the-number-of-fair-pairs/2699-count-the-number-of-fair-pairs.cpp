class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        // create a function to getnumber of element less than or equal to a value.
        // fn(upper) - fn(lower-1) is the answer.
        return getNumberOfPairsWithMaxSumLimit(upper, nums) - getNumberOfPairsWithMaxSumLimit(lower-1, nums); 
    }
private:
    int getNumElemennts(vector<int> &nums, int left, int right, int val) {
        int result = left-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] <= val) {
                result = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return result;
    }

    long long getNumberOfPairsWithMaxSumLimit(int limit, vector<int>& nums) {
        long long answer = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            // since x+num <= limit
            int limitOfOtherElement = limit-nums[i];
            // find number of elements in nums above index i and less than or equal to limitOfOtherElements
            answer += (getNumElemennts(nums, i+1, n-1, limitOfOtherElement)-i);
        }
        return answer;
    }
};