#include <vector>

class Solution {
    int totalSum;
    vector<int> prefixSums;
public:
    Solution(vector<int>& w) {
        int n = w.size();
        prefixSums.resize(n);
        prefixSums[0] = w[0];
        totalSum = w[0];
        for (int i = 1; i < n; ++i) {
            prefixSums[i] = w[i]+prefixSums[i-1];
            totalSum += w[i];
        }
    }
    
    int pickIndex() {
        int idx = rand()%totalSum;
        auto ub = upper_bound(prefixSums.begin(), prefixSums.end(), idx);
        // cout << *ub << endl;
        return (int)(ub - prefixSums.begin());
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
