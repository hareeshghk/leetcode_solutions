class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<vector<int>> intervals = vector<vector<int>>(26, vector<int>(2, -1));
        // create first last intervals of each letter
        for (int i = 0; i < s.length(); ++i) {
            int idx = s[i]-'a';
            if (intervals[idx][0] == -1) {
                intervals[idx][0] = i;
                intervals[idx][1] = i;
            } else {
                intervals[idx][1] = i;
            }
        }

        // sort intervals
        sort(intervals.begin(), intervals.end());

        vector<int> answer;
        // merge intervals and return size of each.
        int i = 0;
        // skipping intervaks for all non existing ones.
        while (i < intervals.size() && intervals[i][0] == -1) ++i;
        
        while (i < intervals.size()) {
            int j = i+1;
            int end = intervals[i][1];
            while (j < intervals.size()) {
                if (intervals[j][0] > end) {
                    break;
                }
                end = max(intervals[j][1], end);
                j++;
            }
            answer.push_back((end - intervals[i][0]) + 1);
            i = j;
        }
        return answer;
    }
};