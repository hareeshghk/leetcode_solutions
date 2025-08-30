#include <unordered_map>
#include <vector>

class Solution {
    int mod = 1000000007;
    int _m;
public:
    int colorTheGrid(int m, int n) {
        _m = m;
        vector<int> states = enumerateStates();
        unordered_map<int, vector<int>> neighbours;
        for (int i = 0; i < states.size(); ++i) {
            for (int j = i+1; j < states.size(); ++j) {
                if (validState(states[i], states[j])) {
                    neighbours[states[i]].push_back(states[j]);
                    neighbours[states[j]].push_back(states[i]);
                }
            }
        }

        unordered_map<int, int> count1;
        for (auto state : states) {
            count1[state] = 1;
        }

        for (int i = n-2; i >= 0; --i) {
            unordered_map<int, int> count2;

            for (auto state : states) {
                int result = 0;
                for (auto nei : neighbours[state]) {
                    result = (result + count1[nei])%mod;
                }
                count2[state] = result;
            }

            count1 = count2;
        }

        int answer = 0;

        for (auto state : states) {
            answer = (answer + count1[state]) % mod;
        }
        return answer;
    }
private:
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
