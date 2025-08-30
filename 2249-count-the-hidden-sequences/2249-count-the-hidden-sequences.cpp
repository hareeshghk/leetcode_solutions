#include <algorithm>
#include <vector>

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long minVal=INT_MAX, maxVal=INT_MIN;
        long long currSum = 0;
        for (int diff : differences) {
            currSum += diff;
            minVal = min(minVal, currSum);
            maxVal = max(maxVal, currSum);
        }

        long long answer = upper-lower+1;

        if (minVal < 0) {
            answer = max(0LL, answer+minVal);
        }

        if (maxVal > 0) {
            answer = max(0LL, answer-maxVal);
        }
        return (int)answer;
    }
};
