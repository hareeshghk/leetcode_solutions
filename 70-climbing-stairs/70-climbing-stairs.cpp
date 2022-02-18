class Solution {
public:
    int climbStairs(int n) {
        if (n<=2) return n;
        vector<vector<long long int>> multiplier {{1,1},{1,0}};
        auto result = matrixpower(multiplier, n-2);
        return result[0][0]*2 + result[0][1];
    }
    
    vector<vector<long long int>> matrixpower(vector<vector<long long int>> base, int exp) {
        vector<vector<long long int>> result {{1,0},{0,1}};
        while (exp > 0) {
            if (exp & 1) {
                result = multiply(result, base);
            }
            exp = exp >>1;
            base = multiply(base, base);
        }
        return result;
    }
    
    vector<vector<long long int>> multiply(vector<vector<long long int>> a, vector<vector<long long int>> b) {
        vector<vector<long long int>> c(2, vector<long long int>(2));
        
        c[0][0] = a[0][0]*b[0][0]+a[0][1]*b[1][0];
        c[0][1] = a[0][0]*b[0][1]+a[0][1]*b[1][1];
        c[1][0] = a[1][0]*b[0][0]+a[1][1]*b[1][0];
        c[1][1] = a[1][0]*b[0][1]+a[1][1]*b[1][1];
        return c;
    }
};