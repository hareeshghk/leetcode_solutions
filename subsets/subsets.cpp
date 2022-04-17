class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        
        result.push_back({});
        
        for (auto num : nums) {
            int k = result.size();
            for (int i = 0; i < k; ++i) {
                auto cur = result[i];
                cur.push_back(num);
                result.push_back(cur);
            }
        }
        return result;
    }
};