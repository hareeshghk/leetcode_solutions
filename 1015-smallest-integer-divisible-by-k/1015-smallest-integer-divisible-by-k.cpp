class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int val = 1;
        int len = 1;
        for (int i = 0; i <= k; ++i) {
            if (val % k == 0) return len;

            val = ((val * 10)%k + 1)%k;
            len++;
        }
        return -1;
    }
};