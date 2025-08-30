#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        
        vector<vector<int>> result;
        
        int idx = 0;
        
        while (idx < n) {
            if (intervals[idx][1] < newInterval[0]) {
                result.push_back(intervals[idx]);
                ++idx;
            } else break;
        }
        
        while (idx < n) {
            if (newInterval[1] < intervals[idx][0]) {
                break;
            } else {
                newInterval[0] = min(newInterval[0], intervals[idx][0]);
                newInterval[1] = max(newInterval[1], intervals[idx][1]);
            }
            ++idx;
        }
        
        result.push_back(newInterval);
        
        while (idx < n) {
            result.push_back(intervals[idx++]);
        }
        
        return result;
    }
};
