#include <unordered_map>
#include <vector>

class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        unordered_map<int, int> counter;
        
        int n = arrays.size();
        vector<int> ans;
        
        // O(mn)
        for (int i = 0; i < n-1; ++i) {
            for (int j = 0; j<arrays[i].size(); ++j) {
                counter[arrays[i][j]]++;
            }
        }
        
        for (int i = 0; i<arrays[n-1].size(); ++i) {
            counter[arrays[n-1][i]]++;
            if (counter[arrays[n-1][i]] == n) ans.push_back(arrays[n-1][i]);
        }
        
        return ans;
    }
};
