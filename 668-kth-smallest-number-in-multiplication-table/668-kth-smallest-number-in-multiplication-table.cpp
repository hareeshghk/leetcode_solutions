class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m*n;
        while (lo < hi) {
            int mi = (lo + hi)/2;
            if (!isPossible(mi, m, n, k)) {
                lo = mi+1;
            } else {
                hi = mi;
            }
        }
        return lo;
    }
    
    bool isPossible(int mi, int m, int n, int k) {
        int count = 0;
        for (int i = 1; i <= m; ++i) {
            count += min(mi/i, n);
        }
        return count >=k;
    }
    
};