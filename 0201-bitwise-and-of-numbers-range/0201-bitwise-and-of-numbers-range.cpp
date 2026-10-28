class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;

        int x = left ^ right;

        while (x != 0) {
            x >>= 1;
            count++;
        }

        return (((left&right) >> count) << count);
    }
};