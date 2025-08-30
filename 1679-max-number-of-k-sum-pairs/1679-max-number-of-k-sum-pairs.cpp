#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        
        for (auto num : nums) {
            counts[num]++;
        }
        
        int result = 0;
        for (auto val : counts) {
            int num = val.first;
            int freq = val.second;
            
            if (k-num == num) {
                result += freq/2;
                counts[num] = 1;
                continue;
            }
            if (counts.find(k-num) != counts.end()) {
                int freq2 = counts[k-num];
                counts[k-num] -= min(freq, freq2);
                counts[num] -= min(freq, freq2);
                result += min(freq, freq2);
            }
        }
        return result;
    }
};
