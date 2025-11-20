class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k%5 == 0) return -1;
        int num = 1;
        int ans = 1;
        while (num != 0) {
            while (num < k) {
                num = (num * 10) + 1;
                ans++;
            }

            num = num%k;
        }
        return ans;
    }
};