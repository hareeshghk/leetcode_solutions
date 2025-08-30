#include <string>

class Solution {
public:
    const int mod = 1000000007;
    int numberOfWays(string corridor) {
        int numchairs = 0;
        for (int i = 0; i < corridor.length(); ++i) {
            if (corridor[i] == 'S') ++numchairs;
        }
        
        if (numchairs == 0 || ((numchairs%2) != 0)) return 0;
        
        return ((int)numways(corridor, 0));
    }
    
    long numways(const string &c, int index) {
        if (index == c.length()) {
            return 1;
        }
        
        int numchairs = 0;
        int i =  index;
        while (i < c.length()) {
            if (c[i] == 'S') {
                ++numchairs;
            }
            ++i;
            
            if (numchairs == 2) {
                break;
            }
        }
        
        if (numchairs == 0) return 1;
        if (numchairs == 1) return 0;
        
        long numFlowers = 0;
        int j = i;
        while (j < c.length() && c[j] =='P') {
            ++j;
            numFlowers++;
        }
        
        if (j == c.length()) return 1;
        
        return ((numFlowers+1) * (numways(c, j)%mod))%mod;
    }
};
