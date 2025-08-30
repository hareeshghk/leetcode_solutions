#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        if (n<2) return 0;
        
        int v1 = 0;
        int v2 = 0;
        int temp;
        for (int i =2; i<=n;i++) {
            temp = min(v1+cost[i-2], v2+cost[i-1]);
            v1 = v2;
            v2 = temp;
        }
        return v2;
    }
};
