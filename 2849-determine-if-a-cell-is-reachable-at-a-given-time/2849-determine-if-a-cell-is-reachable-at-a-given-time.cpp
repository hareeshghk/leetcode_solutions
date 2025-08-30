#include <algorithm>
#include <cmath>

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int minstepsneeded = max(abs(sx-fx), abs(sy-fy));
        if (t == 1) {
            return minstepsneeded==1;
        }
        return t >= minstepsneeded;
    }
};
