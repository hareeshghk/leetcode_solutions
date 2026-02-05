class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> result = vector<int>(n);
        int val = getVal(n);
        for (int i = 0; i < n; ++i) {
            result[i] = nums[(i+nums[i]+val) %n];
        }
        return result;
    }
private:
    int getVal(int n) {
        int ans = n;
        while (ans <= 100) {
            ans += n;
        }
        return ans;
    }
};