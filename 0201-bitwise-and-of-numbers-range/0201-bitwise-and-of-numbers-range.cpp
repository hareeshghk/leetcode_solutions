class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        vector<int> leftbits = vector<int>(32,0);
        vector<int> rightbits = vector<int>(32,0);

        int counter = 0;

        while (counter < 32) {
            if (left & 1) {
                leftbits[counter] = 1;
            }

            if (right & 1) {
                rightbits[counter] = 1;
            }

            counter++;
            left >>=1;
            right >>=1;
        }

        int bp = 31;

        for (bp = 31; bp >=0; --bp) {
            if (leftbits[bp] != rightbits[bp]) break;
        }

        int ans = 0;

        for (int i = 31; i > bp; --i) {
            ans <<=1;
            ans += leftbits[i];
        }

        for (int i = bp; i >=0; --i) {
            ans <<= 1;
        }

        return ans;
    }
};