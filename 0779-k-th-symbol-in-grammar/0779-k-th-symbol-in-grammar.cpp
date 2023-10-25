class Solution {
public:
    int kthGrammar(int n, int k) {
        int left, right, val;
        left = 1;
        right = (1<<n)-1;
        
        int depth = 1;
        val = 0;
        while (depth <= n) {
            int mid = (left +  right)/2;
            
            if (k <= mid) {
                right = mid;
            } else {
                left = mid+1;
                
                val ^= 1;
            }
            depth++;
        }
        
        return val;
    }
};