#include <unordered_map>
#include <vector>

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();

        int prefixCount = 0, findCount;
        unordered_map<int, int> modCount;
        long long answer = 0;
        modCount[0] = 1;
        for (int i = 0; i < n; ++i) {
            if ((nums[i] % modulo) == k) {
                prefixCount++;
            }

            findCount = ((prefixCount-k)+modulo) % modulo;

            answer += modCount[findCount];
            modCount[prefixCount%modulo]++;
        }

        return answer;
    }
};
