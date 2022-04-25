class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1 || x==0) return x;
        
        if (n < 0) {
            x = 1/x;
            if (n == INT_MIN) {
                return (getPow(x, INT_MAX)*x);
            }
            n = -n;
        }
        
        return getPow(x, n);
    }
    
    double getPow(double x, int n) {
        double result = 1.0;
        while (n != 0) {
            if (n&1) {
                result = result*x;
            }
            
            n = n>>1;
            
            x = x*x;
        }
        
        return result;
    }
};