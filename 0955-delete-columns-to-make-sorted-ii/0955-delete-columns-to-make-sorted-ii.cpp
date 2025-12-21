class Solution {
public:
    int n;
    int minDeletionSize(vector<string>& strs) {
        n = strs.size();
        set<int> indicesPresent;
        for (int i = 1; i < n; ++i) {
            indicesPresent.insert(i);
        }
        return getMinDeletionSize(strs, 0, indicesPresent);
    }
private:
    int getMinDeletionSize(vector<string> &strs, int index, set<int> &indicesPresent) {
        if (index == strs[0].size() || indicesPresent.size() == 0) {
            return 0;
        }

        set<int> indices;
        bool isBreak = false;
        for (auto idx : indicesPresent) {
            if (strs[idx][index] < strs[idx-1][index]) {
                isBreak = true;
                break;
            } else if (strs[idx][index] == strs[idx-1][index]) {
                indices.insert(idx);
            }
        }

        if (!isBreak) {
            return getMinDeletionSize(strs, index+1, indices);
        } else {
            return 1 + getMinDeletionSize(strs, index+1, indicesPresent);
        }
    }
};