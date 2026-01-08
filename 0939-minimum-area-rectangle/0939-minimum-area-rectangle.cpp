class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int n = points.size();
        int val = 40001;
        
        set<int> seen;
        for (auto p : points) {
            seen.insert(p[0]*val + p[1]);
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (points[i][0] != points[j][0] && points[i][1] != points[j][1]) {
                    if ((seen.find(points[i][0] * val + points[j][1]) != seen.end()) && (seen.find(points[j][0] * val + points[i][1]) != seen.end())) {
                        ans = min(ans, abs(points[i][1]-points[j][1]) * abs(points[i][0]-points[j][0]));
                    }
                }
            }
        }

        if (ans == INT_MAX) return 0;
        return ans;
    }
};