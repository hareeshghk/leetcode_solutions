#include <vector>

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int nums = 1<<n;
        vector<int> result(nums);
        result[0] = 0;
        result[1] = 1;
        int cursize = 2;
        int startidx;
        if (start == 0 || start == 1) {
            startidx = start;
        }
        for (int i = 1; i < n; i++) {
            int curdiff = 1<<i;
            for (int j = 0; j < cursize; j++) {
                result[2*cursize -1 -j] = result[j]+curdiff;
                if (result[2*cursize -1 -j] == start) {
                    startidx = 2*cursize -1 -j;
                }
            }
            cursize <<=1;
        }
        
        // rotate from start
        rotate(result.begin(), result.begin()+startidx, result.end());
        return result;
    }
};
