class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> nums;

        for (auto answer : answers) {
            nums[answer]++;
        }

        int result = 0;

        for (auto& val : nums) {
            result += ((val.second + val.first) / (val.first+1)) * (val.first+1);
        }
        return result;
    }
};