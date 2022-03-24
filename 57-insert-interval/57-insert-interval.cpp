class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if (n==0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        vector<vector<int>> result;
        // find position for new interval.
        // newinterval at start
        if (newInterval[1] < intervals[0][0]) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        
        // newinterval at end
        if (newInterval[0] > intervals[n-1][1]) {
            intervals.push_back(newInterval);
            return intervals;
        }
        
        // find position for new interval through binary search
        int l = 0, r = n-1, mid;
        
        while (l<r) {
            mid = (l+r)/2;
            if (intervals[mid][1] < newInterval[0]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        
        for (int i = 0; i < l; i++) {
            result.push_back(intervals[i]);
        }
        
        int start = newInterval[0];
        int end = newInterval[1];
        while (l < n && end >= intervals[l][0]) {
            start = min(start, intervals[l][0]);
            end = max(end, intervals[l][1]);
            l++;
        }
        
        result.push_back({start, end});
        
        for (int i = l; i < n; i++) {
            result.push_back(intervals[i]);
        }
        return result;
    }
};