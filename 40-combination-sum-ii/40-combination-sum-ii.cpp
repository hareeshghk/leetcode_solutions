#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> intaken;
    vector<int> candidates;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        solve(target, 0);
        return ans;
    }
    
    void solve(int target, int idx) {
        if (target == 0) {
            ans.push_back(intaken);
            return;
        }
        if (target < 0 || idx == candidates.size()) return;

        for (int i = idx; i<candidates.size(); i++) {
            intaken.push_back(candidates[i]);
            solve(target-candidates[i], i+1);
            intaken.pop_back();
            while (i+1 < candidates.size() && candidates[i] == candidates[i+1]) {
                i++;
            }
        }
        return;
    }
};
