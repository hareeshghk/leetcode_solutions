class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> getFactors(int n) {
        getFactors(n, 2, {});
        return result;
    }
    
    void getFactors(int n, int start, vector<int> cur) {
        if (n==1) {
            if (cur.size() > 1) result.push_back(cur);
            return;
        }
        
        for (int i = start; i <= n; ++i) {
            if ((n%i) == 0) {
                cur.push_back(i);
                getFactors(n/i, i, cur);
                cur.pop_back();
            }
        }
    }
};