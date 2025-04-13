class Solution {
public:
    int countGoodNumbers(long long n) {
        // example length 4
        // 0,1,2,3 are indices
        // position 0,2 should be even and 1,3 should be prime digit.
        // we have 5 even digits 0,2,4,6,8 and 4 prime digits 2,3,5,7
        // 5 * 4 * 5 * 4 = 5^(n+1)/2 * 4^n/2
        int mod = 1000000007;
        long long answer = (fastExponentiation(5, (n+1)/2, mod) * fastExponentiation(4, n/2, mod)) %mod;

        return (int)answer;
    }
private:
    long long fastExponentiation(long long base, long long exponent, int mod) {
        long long result  = 1;
        while (exponent != 0) {
            if (exponent & 1) {
                result = (result * base)%mod;
            }
            base = (base * base) %mod;
            exponent /= 2;
        }
        return result;
    }
};