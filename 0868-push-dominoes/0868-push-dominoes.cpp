class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();

        vector<int> inclination = vector<int>(n, -1);
        int currentRightFlow = -1;
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'R') {
                currentRightFlow = 0;
            } else if (dominoes[i] == 'L') {
                currentRightFlow = -1;
            } else {
                if (currentRightFlow >= 0) {
                    currentRightFlow++;
                }
            }
            inclination[i] = currentRightFlow;
        }

        string answer(n, '.');
        int currentLeftFlow = -1;
        for (int i = n-1; i >=0; --i) {
            if (dominoes[i] == 'L') {
                currentLeftFlow = 0;
            } else if (dominoes[i] == 'R') {
                currentLeftFlow = -1;
            } else {
                if (currentLeftFlow >= 0) {
                    currentLeftFlow++;
                }
            }

            if (dominoes[i] == '.') {
                if (currentLeftFlow == -1) {
                    if (inclination[i] > 0) {
                        answer[i] = 'R';
                    }
                } else {
                    if (inclination[i] == -1) {
                        answer[i] = 'L';
                    } else {
                        if (currentLeftFlow < inclination[i]) {
                        answer[i] = 'L';
                    } else if (currentLeftFlow > inclination[i]) {
                        answer[i] = 'R';
                    }
                    }
                    
                }
            } else {
                answer[i] = dominoes[i];
            }
        }
        return answer;
    }
};