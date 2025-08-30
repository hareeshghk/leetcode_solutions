#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        
        for (auto price : prices) {
            maxProfit = max(maxProfit, price-minPrice);
            minPrice = min(price, minPrice);
        }
        
        return maxProfit;
    }
};
