class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int, int> pos;
        int overallMod = 0;

        for (auto num : nums) {
            overallMod = (overallMod+num) %p;
        }
        if (overallMod == 0) return 0;

        pos[0] = -1;
        
        int curMod, neededMod, answer = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            curMod = (curMod+nums[i])%p;
            neededMod = (p + curMod - overallMod)%p;

            if (pos.find(neededMod) != pos.end()) {
                answer = min(answer, i-pos[neededMod]);
            } 
            pos[curMod] = i;
        }

        if (answer == nums.size()) return -1;

        return answer;
    }
};