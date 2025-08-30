#include <algorithm>
#include <queue>
#include <vector>

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, greater<int>> minheap;
        int result = INT_MIN;
        for (int i = 0; i < intervals.size(); i++) {
            if (!minheap.empty() && minheap.top() <= intervals[i][0]) {
                minheap.pop();
            }
            minheap.push(intervals[i][1]);
        }
        return minheap.size();
    }
};
