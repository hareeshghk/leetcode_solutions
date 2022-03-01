class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        if (n==0) return {0};
        if (n==1) return {0,1};
        
        ans.push_back(0);
        ans.push_back(1);
        
        int count = 2;
        int start = 1, end = 1;
        while (count <= n+1) {
            for (int j = start; j<=end && (count != n+1); ++j) {
                ans.push_back(ans[j]);
                count++;
            }
            if (count == n+1) break;
            for (int j = start; j<=end && (count != n+1); ++j) {
                ans.push_back(ans[j]+1);
                count++;
            }
            if (count == n+1) break;
            start = end+1;
            end = ans.size()-1;
        }
        return ans;
    }
};