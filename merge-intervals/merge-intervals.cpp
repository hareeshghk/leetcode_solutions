#include <algorithm>
#include <vector>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        int ans_idx = 0;
        
        for (int idx = 1; idx < intervals.size(); ++idx) {
            if (end < intervals[idx][0]) {
                intervals[ans_idx][0] = start;
                intervals[ans_idx][1] = end;
                ++ans_idx;
                start = intervals[idx][0];
                end = intervals[idx][1];
            } else {
                start = min(start, intervals[idx][0]);
                end = max(end, intervals[idx][1]);
            }
        }
        
        intervals[ans_idx][0] = start;
        intervals[ans_idx][1] = end;
        intervals.erase(intervals.begin()+ans_idx+1, intervals.end());
        return intervals;
    }
};
