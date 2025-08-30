#include <algorithm>
#include <vector>

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> values(20001, 0);
        
        for (auto num : nums) {
            values[num] += num;
        }
        
        int take=0, skip=0;
        for (int i = 0; i < values.size(); ++i) {
            int takenow = skip + values[i];
            int skipnow = max(take, skip);
            take = takenow;
            skip = skipnow;
        }
        return max(skip, take);
    }
};
