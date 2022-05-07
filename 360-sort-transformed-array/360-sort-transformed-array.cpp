class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        for (auto &num :nums) {
            num = a*(num*num) + b*num +c;
        }
        
        sort(nums.begin(), nums.end());
        return nums;
    }
};