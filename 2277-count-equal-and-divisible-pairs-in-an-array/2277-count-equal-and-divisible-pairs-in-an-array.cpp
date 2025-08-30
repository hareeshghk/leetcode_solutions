#include <unordered_map>
#include <vector>

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        // we have n2 solution
        // int answer = 0;
        // for (int i = 0; i < nums.size(); ++i) {
        //     for (int j = i+1; j < nums.size(); ++j) {
        //         if (nums[i]==nums[j] && ((i*j)%k==0)) ++answer;
        //     }
        // }
        // return answer;

        int n = nums.size();
        unordered_map<int, vector<int>> numberIndexMap;
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            auto& vals = numberIndexMap[nums[i]];
            for (auto val : vals) {
                if ((i*val)%k == 0) ++answer;
            } 
            numberIndexMap[nums[i]].push_back(i);
        }
        return answer;
    }
};
