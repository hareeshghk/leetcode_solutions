#include <cmath>

class Solution {
public:
    int getSum(int a, int b) {
        int x = abs(a), y = abs(b);
        
        // idea is if we need sum positives and negatives doesnt matter on order.
        // for negative number and positive number we can do subtract small from large and apply sign.
        // 3 ,-5 converts to -5, 3 which will convert to -1 *(5-3)
        // we need to handle big + small or big - small only.
        if (x < y) return getSum(b, a);
        
        // if first number if negative then take out negative sign and do remaining op.
        int sign;
        if (a < 0) {
            sign = -1;
        } else {
            sign = 1;
        }
        
        int sum = x , carry = y, temp;
        if (a*b > 0) {
            while (carry != 0) {
                temp = sum^carry;
                carry = (sum & carry) << 1;
                sum = temp;
            }
        } else {
            while (carry != 0) {
                temp = sum^carry;
                carry = ((~sum) &carry) << 1;
                sum = temp;
            }
        }

        return sum * sign;
    }
};
