class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans = vector<vector<int>>();
        vector<int> runningVector = vector<int>();
        getCombinations(ans, runningVector, 1, n, k);
        return ans;
    }
private:
    void getCombinations(vector<vector<int>> &ans, vector<int> &r, int start, int n, int k) {
        if (k == 0) {
            ans.push_back(r);
            return;
        }

        for (int i = start; i <= n; ++i) {
            r.push_back(i);
            getCombinations(ans, r, i+1, n, k-1);
            r.pop_back();
        }
    }
};