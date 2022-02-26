class Solution {
public:
    bool canMeasureWater(int a, int b, int target) {
        int gc = gcd(a,b);
        return (target == 0) || (a+b >= target && target%gc == 0);
    }
    
    int gcd(int a, int b) {
        int temp;
        while (b!=0) {
            temp = a%b;
            a = b;
            b = temp;
        }
        return a;
    }
};