class Solution {
public:
    int n;
    int minDeletionSize(vector<string>& strs) {
        n = strs.size();
        vector<bool> indicesPresent = vector<bool>(n, true);
        return getMinDeletionSize(strs, 0, indicesPresent);
    }
private:
    int getMinDeletionSize(vector<string> &strs, int index, vector<bool>& indicesPresent) {
        if (index == strs[0].size()) {
            return 0;
        }

        int answer = 0;
        vector<bool> indices = vector<bool>(n, false);
        int idx = 0;
        for (idx = 1;idx < n; ++idx) {
            if (indicesPresent[idx]) {
                if (strs[idx][index] < strs[idx-1][index]) {
                    answer++;
                    break;
                } else if (strs[idx][index] == strs[idx-1][index]) {
                    indices[idx] = true;
                }
            }
        }

        int val = 0;
        if (idx == n) {
            val = getMinDeletionSize(strs, index+1, indices);
        } else {
            val = getMinDeletionSize(strs, index+1, indicesPresent);
        }

        return answer + val;
    }
};