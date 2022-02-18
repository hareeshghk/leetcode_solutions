class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        int start = intervals[0][0];
        int end = intervals[0][1];
        
        vector<vector<int>> ans;
        
        for (int idx = 1; idx < intervals.size(); ++idx) {
            if (end < intervals[idx][0]) {
                ans.push_back({start, end});
                start = intervals[idx][0];
                end = intervals[idx][1];
            } else {
                start = min(start, intervals[idx][0]);
                end = max(end, intervals[idx][1]);
            }
        }
        
        ans.push_back({start, end});
        return ans;
    }
};