class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int num = 1;
        int ans = 1;

        while (num != 0) {
            while (num < k) {
                num = (num * 10) + 1;
                ans++;
            }

            num = num%k;
            if (ans > 100000) return -1;
        }
        return ans;
    }
};