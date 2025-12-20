class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();

        int toatalColumns = strs[0].length();
        int answer = 0;

        vector<bool> stillConsidered = vector<bool>(toatalColumns, true);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < toatalColumns; ++j) {
                if (!stillConsidered[j]) continue;

                if ((strs[i][j] -'a') < (strs[i-1][j] -'a')) {
                    answer++;
                    stillConsidered[j] = false;
                }
            }
        }
        return answer;
    }
};