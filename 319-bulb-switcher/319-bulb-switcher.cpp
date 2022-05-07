class Solution {
public:
    int bulbSwitch(int n) {
        if (n==0) return 0;
        if (n==1) return 1;
        int left = 1, right = min((int)sqrt(INT_MAX),n/2);
        int potential_ans = 1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            int val = mid*mid;
            if (val == n) {
                return mid;
            }
            
            if (val < n) {
                potential_ans = mid;
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return potential_ans;
    }
};