class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();

        int prefixCount = 0;
        unordered_map<int, int> modCount;
        long long answer = 0;
        modCount[0] = 1;
        for (int i = 0; i < n; ++i) {
            if ((nums[i] % modulo) == k) {
                prefixCount++;
            }

            int findCount = (prefixCount-k) % modulo;

            answer += modCount[findCount];
            modCount[prefixCount%modulo]++;
        }

        return answer;
    }
};