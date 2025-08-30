#include <algorithm>
#include <vector>

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
        int n = d.size();
        int answer = 0;

        vector<vector<int>> counter = vector<vector<int>>(10, vector<int>(10, 0));

        for (int i =0 ; i < n; ++i) {
            counter[d[i][0]][d[i][1]]++;
        }

        int currentCount;
        for (int i = 1; i <= 9; ++i) {
            answer += max(0, (counter[i][i] * (counter[i][i]-1)) / 2);
            for (int j = i+1; j <= 9; ++j) {
                currentCount = counter[i][j] + counter[j][i];
                answer += max(0, (currentCount * (currentCount-1))/2);
            }
        }
        return answer;
    }
};
