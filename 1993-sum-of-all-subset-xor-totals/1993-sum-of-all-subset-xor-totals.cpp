class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int answer = 0;
        int n = nums.size();

        vector<int> existingXors;
        existingXors.push_back(0);

        int val;
        for (int i = 0; i < n; ++i) {
            int currSize = existingXors.size();
            for (int j = 0; j < currSize; ++j) {
                val = existingXors[j]^nums[i];
                answer += val;
                existingXors.push_back(val);
            }
        }
        return answer;
    }
};