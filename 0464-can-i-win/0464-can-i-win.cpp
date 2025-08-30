#include <algorithm>
#include <unordered_map>

class Solution {
    int desired;
    int maxchoosable;
    unordered_map<int, bool> dp;
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int state = 0;
        desired = desiredTotal;
        maxchoosable = maxChoosableInteger;
        int totalSum = (maxChoosableInteger * (maxChoosableInteger+1))/2;

        if (totalSum < desiredTotal) return false;
        return isPossible(0, 0, state);
    }

    bool isPossible(int turn, int cursum, int state) {
        if (dp.find(state) != dp.end()) {
            return dp[state];
        }
        for (int i = 1; i <= maxchoosable; ++i) {
            if ((state & (1<<i)) == 0) {
                if ((cursum+i >= desired) || (isPossible(1-turn, cursum+i, state | (1<<i)) == false)) {
                    dp[state] = true;
                    return true;
                }
            }
        }
        dp[state] = false;
        return false;
    }
};
