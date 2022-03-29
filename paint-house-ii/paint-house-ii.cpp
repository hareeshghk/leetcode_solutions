class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int m = costs.size();
        int k = costs[0].size();
        int mv1,mv2,tempmv1,tempmv2;
        mv1=mv2=INT_MAX;
        for (int i =0;i<k;++i) {
            if (costs[0][i] <=mv1) {
                mv2 = mv1;
                mv1 = costs[0][i];
            } else if (costs[0][i] < mv2) {
                mv2 = costs[0][i];
            }
        }
        for (int i = 1; i < m; ++i) {
            tempmv1=tempmv2=INT_MAX;
            for (int j = 0; j < k;j++) {
                if (costs[i-1][j]==mv1) {
                    costs[i][j] += mv2;
                } else {
                    costs[i][j] += mv1;
                }
                if (costs[i][j] <= tempmv1) {
                    tempmv2 = tempmv1;
                    tempmv1 = costs[i][j];
                } else if(costs[i][j]<tempmv2) {
                    tempmv2 = costs[i][j];
                }
            }
            mv1 = tempmv1;
            mv2 = tempmv2;
        }
        
        return mv1;
    }
    
    int getmin(vector<int> &costs, int excluded) {
        int minval = INT_MAX;
        
        for (int i = 0; i < costs.size();++i) {
            if (i==excluded) continue;
            minval = min(minval, costs[i]);
        }
        return minval;
    }
};