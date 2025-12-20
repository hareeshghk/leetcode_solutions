class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();

        int toatalColumns = strs[0].length();
        int answer = 0;

        for (int i = 0; i < toatalColumns; ++i) {
            for (int j = 1; j < n; ++j) {
                if ((strs[j][i] - 'a') < (strs[j-1][i] - 'a')) {
                    answer++;
                    break;
                }
            }
        }
        return answer;
    }
};