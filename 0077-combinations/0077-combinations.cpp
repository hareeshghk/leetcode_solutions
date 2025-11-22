class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<bool> nums = vector<bool>(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = true;
        }

        vector<vector<int>> ans = vector<vector<int>>();
        vector<int> runningVector = vector<int>();
        getCombinations(ans, runningVector, nums, k);
        return ans;
    }
private:
    void getCombinations(vector<vector<int>> &ans, vector<int> &r, vector<bool> &nums, int k) {
        if (k == 0) {
            ans.push_back(r);
            return;
        }

        int min = r.size()>0?r.back():0;
        for (int i = min; i < nums.size(); ++i) {
            if (nums[i]) {
                nums[i] = false;
                r.push_back(i+1);
                getCombinations(ans, r, nums, k-1);
                r.pop_back();
                nums[i] = true;
            }
        }
    }
};