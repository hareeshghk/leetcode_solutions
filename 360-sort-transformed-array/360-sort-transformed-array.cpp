#include <vector>

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        bool is_upward = true;
        if (a<0) {
            is_upward = false;
            a = -a;
            b = -b;
            c = -c;
        }
        vector<int> result (nums.size(), 0);
        int idx = nums.size()-1;
        
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int leftval = getVal(nums[left], a, b, c);
            int rightval = getVal(nums[right], a, b, c);
            if (leftval <= rightval) {
                result[idx--] = rightval;
                right--;
            } else {
                result[idx--] = leftval;
                left++;
            }
        }
        
        if (!is_upward) {
            left = 0, right = result.size()-1;
            while (left < right) {
                result[left] = -result[left];
                result[right] = -result[right];
                swap(result[left], result[right]);
                left++;
                right--;
            }
            
            if (left == right) {
                result[left] = -result[left];
            }
        }
        
        return result;
    }
    
    int getVal(int x, int a, int b, int c) {
        return a*(x*x) + b*x + c;
    }
};
