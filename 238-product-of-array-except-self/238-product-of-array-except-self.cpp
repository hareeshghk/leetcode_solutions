#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int val = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = val;
            val *= nums[i];
        }
        
        int suffix_product = 1;
        for (int i = n-1; i >= 0; i--) {
            ans[i] = (ans[i])*suffix_product;
            suffix_product *= nums[i];
        }
        return ans;
    }
};
