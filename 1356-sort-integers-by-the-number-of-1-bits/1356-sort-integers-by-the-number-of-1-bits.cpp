#include <algorithm>
#include <vector>

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto numOfOnes = [](int a) {
            int ans = 0;
            
            while (a!=0) {
                if (a & 1) ans++;
                a >>=1;
            }
            return ans;
        };
        
        sort(arr.begin(), arr.end(), [numOfOnes](int a, int b) {
          int aones = numOfOnes(a);
            int bones = numOfOnes(b);
            if (aones < bones) {
              return true;
            } else if (aones == bones) {
                return a < b;
            }
            return false;
        });
        
        return arr;
    }
};
