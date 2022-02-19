class Solution {
public:
    int mySqrt(int x) {
        if (x==0) return 0;
        if (x<=3) return 1;
        int left = 2, right = x/2;
        long long int val;
        while (left <= right) {
            int mid = left + (right-left)/2;
            val = (long long)mid * mid;
            
            if (val > x) {
                right = mid -1;
            } else if (val == x) {
                return mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }
};