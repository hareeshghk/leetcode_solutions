class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        
        if (intervals.size() == 0) return result;
        
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {return a[0]<b[0];});
        
        auto curInterval = intervals[0];
        
        for (int i = 1; i < intervals.size(); ++i) {
            if (curInterval[1] < intervals[i][0]) {
                result.push_back(curInterval);
                curInterval = intervals[i];
            } else {
                curInterval[0] = min(curInterval[0], intervals[i][0]);
                curInterval[1] = max(curInterval[1], intervals[i][1]);
            }
        }
        
        result.push_back(curInterval);
        return result;
    }
};