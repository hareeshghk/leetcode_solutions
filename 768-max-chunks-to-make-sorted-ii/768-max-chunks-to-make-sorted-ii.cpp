#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> maxarr(n), minarr(n);
        
        int maxtillnow = INT_MIN;
        int mintillnow = INT_MAX;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            maxtillnow = max(maxtillnow, arr[i]);
            maxarr[i] = maxtillnow;
            mintillnow = min(mintillnow, arr[n-1-i]);
            minarr[n-1-i] = mintillnow;
        }
        
        for (int i = 0; i<n-1;i++) {
            if (maxarr[i] <= minarr[i+1]) ++result;
        }
        
        return result+1;
    }
};
