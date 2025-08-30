#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> largestOnLeft = vector<int>(n + 1, 0);
        vector<int> largestOnRight = vector<int>(n + 1, 0);
        for (int i = 1; i < n; ++i) {
            largestOnLeft[i] =max(largestOnLeft[i-1], nums[i-1]);
            largestOnRight[(n-1)-i] =max(largestOnRight[(n-1)-i+1], nums[(n-1)-i+1]);
        }

        long long answer = 0;

        for (int i = 1; i < n-1; ++i) {
            answer = max(answer, ((long long)(largestOnLeft[i] - nums[i])) * largestOnRight[i]);
        }
        return answer;
    }
};
