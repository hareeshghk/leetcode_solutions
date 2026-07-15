class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int a = n * n;
        int b = n * (n + 1);

        return gcd(b, a);
    }
private:
    int gcd(int a, int b) {
        if (a%b == 0) return b;

        return gcd(b, a%b);
    }
};