class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        unordered_map<int, int> counter;
        
        // O(mn)
        for (int i = 0; i<arrays.size(); ++i) {
            for (int j = 0; j<arrays[i].size(); ++j) {
                counter[arrays[i][j]]++;
            }
        }
        
        int n = arrays.size();
        vector<int> ans;
        
        // O(mn)
        for (auto count : counter) {
            if (count.second == n) ans.push_back(count.first);
        }
        
        // O(n)
        sort(ans.begin(), ans.end());
        return ans;
    }
};