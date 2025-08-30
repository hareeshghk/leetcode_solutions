#include <vector>

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        vector<double> dp1(query_row+1, 0), dp2(query_row+1, 0);
        
        // initial glass.
        dp1[0] = (double)poured;
        
        for (int i =1; i <= query_row; ++i) {
            for (int j = 0; j <= i; ++j) {
                // i-1,j and i-1,j-1
                double current = 0;
                
                current += (dp1[j]-1)>=0?((dp1[j]-1.0)/2):0;
                if (j-1 >=0) {
                    current += (dp1[j-1]-1) >=0?((dp1[j-1]-1.0)/2):0;
                }
                
                dp2[j] = current;
            }
            dp1 = dp2;
        }
        return dp1[query_glass]>1?1:dp1[query_glass];
    }
};
