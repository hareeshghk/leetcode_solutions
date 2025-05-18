class Solution {
    int mod = 1000000007;
    int _m, _n;
    vector<vector<int>> dp;
    vector<int> states;
public:
    int colorTheGrid(int m, int n) {
        // colour of each cell depends on previous painted adjacent blocks.
        // If we need to avoid repetiotions we need to find a way to store partial solutions.
        // given m is max 5 and n is 1000. lets store 'm' blocks as out previous state.
        _m = m;
        _n = n;
        int state = 0;
        // lets use red, green blue as 1,2,3.
        dp = vector<vector<int>>(1025, vector<int>(n, -1));
        states = enumerateStates();
        return getCount(state, 0);
    }
private:
    int getCount(int state, int column) {
        if (column == _n) {
            return 1;
        }

        if (dp[state][column] != -1) return dp[state][column];

        int answer = 0;

        for (auto newState : states) {
            if (validState(state, newState)) {
                answer = (answer + getCount(newState, column + 1))%mod;
            }
        }
        return dp[state][column] = answer;
    }

    bool validState(int os, int ns) {
        for (int i = 0; i < _m; ++i) {
            if (os % 4 == ns % 4) return false;
            os >>= 2;
            ns >>= 2;
        }
        return true;
    }

    vector<int> enumerateStates() {
        vector<int> result = vector<int>();

        getCurrentColumn(0, 0, 0, result);
        return result;
    }

    void getCurrentColumn(int currentIndex, int prevChosen, int currentStateTillNow, vector<int> &result) {
        if (currentIndex == _m) {
            result.push_back(currentStateTillNow);
            return;
        }

        int upColour = prevChosen;

        for (int i = 1; i <= 3; ++i) {
            if (upColour != i) {
                getCurrentColumn(currentIndex + 1, i, (currentStateTillNow | (i << (2*currentIndex))), result);
            }
        }
    }
};