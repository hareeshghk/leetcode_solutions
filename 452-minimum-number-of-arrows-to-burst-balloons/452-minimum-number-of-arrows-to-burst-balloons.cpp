#include <algorithm>
#include <vector>

class Solution {
public:
    static bool sorter(const vector<int> &a, const vector<int> &b) {
        return (a[0]<b[0]) || (a[0]==b[0] && a[1]<b[1]);
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort points
        // compare nightbours and have a intersection, if intersection doesnt work move to nect arrow.
        sort(points.begin(), points.end(), sorter);
        
        int start = points[0][0];
        int end = points[0][1];
        int ans = 1;
        
        for (int i =1; i< points.size(); ++i) {
            if (points[i][0] > end) {
                ans++;
                start = points[i][0];
                end = points[i][1];
            } else {
                start = max(start, points[i][0]);
                end = min(end, points[i][1]);
            }
        }
        return ans;
    }
};
