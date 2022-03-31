class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if (h < n) return false;
        int maxelem = piles[0];
        for (int i =1; i < n; ++i) {
            maxelem =max(maxelem, piles[i]);
        }
        
        int left = 1, right = maxelem, ans=maxelem;
        while (left < right) {
            int k = left +(right-left)/2;
            int neededhours = numhourseneeded(piles, k);
            if (neededhours <= h) {
                right = k;
                ans = k;
            } else {
                left = k+1;
            }
        }
        return right;
    }
    
    int numhourseneeded(vector<int> &piles, int k) {
        int count = 0;
        for (int i = 0; i < piles.size(); ++i) {
            count += piles[i]/k;
            if (piles[i]%k != 0) ++count;
        }
        return count;
    }
};