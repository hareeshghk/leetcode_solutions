#include <algorithm>

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0) return true;
        
        int left = 1, right = min(46340, num);
        
        while (left <= right) {
            int mid = left + (right-left)/2;
            
            int val = mid*mid;
            
            if (val == num) return true;
            
            if (val < num) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return false;
    }
};
