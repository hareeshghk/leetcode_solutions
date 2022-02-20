class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        unordered_map<int, int> counter;
        
        int n = arrays.size();
        vector<int> ans;
        
        // O(mn)
        for (int i = 0; i<arrays.size(); ++i) {
            for (int j = 0; j<arrays[i].size(); ++j) {
                counter[arrays[i][j]]++;
                if (i == n-1 && counter[arrays[i][j]] == n) ans.push_back(arrays[i][j]);
            }
        }
        
        return ans;
    }
};