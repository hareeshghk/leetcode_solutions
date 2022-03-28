class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        dp.resize(n, vector<pair<int,int>>(n,make_pair(-1,-1)));
        auto val = findminproduct(arr, 0, n-1);
        return val.first;
    }
    
    vector<vector<pair<int,int>>> dp;
    pair<int,int> findminproduct(vector<int> &arr, int l, int r) {
        if (l==r) {
            return make_pair(0, arr[l]);
        }
        
        if (dp[l][r].first != -1) {
            return dp[l][r];
        }
        
        int minsum = INT_MAX, sum=0, bigleaf;
        for (int i = l; i < r; i++) {
            auto leftval = findminproduct(arr, l, i);
            auto rightval = findminproduct(arr, i+1, r);
            sum = leftval.first+rightval.first+(leftval.second*rightval.second);
            if (sum < minsum) {
                minsum = sum;
                bigleaf = max(leftval.second, rightval.second);
            }
        }
        auto result = make_pair(minsum, bigleaf);
        dp[l][r] = result;
        return result;
    }
};