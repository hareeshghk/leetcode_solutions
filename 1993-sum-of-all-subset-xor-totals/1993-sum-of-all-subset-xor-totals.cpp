class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int answer = 0;
        int n = nums.size();

        vector<int> existingXors;
        existingXors.push_back(0);

        for (int i = 0; i < n; ++i) {
            int cuSize = existingXors.size();
            for (int j = 0; j < cuSize; ++j) {
                answer += (existingXors[j]^nums[i]);
                existingXors.push_back(existingXors[j]^nums[i]);
            }
        }
        return answer;
    }
};