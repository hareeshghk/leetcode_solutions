#include <unordered_map>
#include <vector>

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        const int mod = 1000000007;
        vector<int> revnums;
        unordered_map<int, int> counter;
        int answer = 0;
        for (int i = 0; i < nums.size();++i) {
            int dif = nums[i] - getRev(nums[i]);
            answer = (answer + counter[dif])%mod;
            counter[dif]++;
        }
        
        return answer;
    }
    
    int getRev(int a) {
        int result = 0;
        while (a != 0) {
            result = (result * 10) + a%10;
            a /= 10;
        }
        return result;
    }
};
