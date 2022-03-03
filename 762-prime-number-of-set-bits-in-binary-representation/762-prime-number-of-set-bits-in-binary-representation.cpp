class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // primes below 32.
        unordered_set<int> primes {2,3,5,7,11,13,17,19,23,29,31};
        
        int ans = 0;
        
        for (int i = left; i <= right; ++i) {
            int j = i;
            int c = 0;
            while (j!=0) {
                if (j&1) c++;
                j = j>>1;
            }
            
            if (primes.find(c) != primes.end()) ans++;
        }
        return ans;
    }
};