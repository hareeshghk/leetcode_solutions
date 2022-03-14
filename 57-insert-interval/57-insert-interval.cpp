class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if (n == 0 || intervals[n-1][1] < newInterval[0]) {
            intervals.push_back(newInterval);
            return intervals;
        } else if(intervals[0][0] > newInterval[1]) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        
        int l = 0, r = intervals.size()-1;
        while(l < r) {
            int mid = l +(r-l)/2;
            if (intervals[mid][1] < newInterval[0]) {
                l = mid+1;
            } else {
                r = mid;
            }
        }
        
        vector<vector<int>> result;
        int idx = 0;
        for (idx =0; idx < l; idx++) {
            result.push_back(intervals[idx]);
        }
        
        int start = newInterval[0];
        int end = newInterval[1];
        while (idx < n && !(intervals[idx][0] > end)) {
            start = min(start, intervals[idx][0]);
            end = max(end, intervals[idx][1]);
            idx++;
        }
        result.push_back({start, end});
        
        while (idx < n) {
            result.push_back(intervals[idx]);
            idx++;
        }
        
        return result;
    }
};