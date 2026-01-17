class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        vector<vector<int>> result = vector<vector<int>>(n);

        for (int i = 0; i < n; ++i) {
            result[i] = {bottomLeft[i][0], bottomLeft[i][1], topRight[i][0], topRight[i][1]};
        }

        sort(result.begin(), result.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] < b[0]) return true;
            if (a[0]==b[0] && a[1] < b[1]) return true;
            return false;
        });

        long long maxArea = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i-1; j>=0; --j) {
                maxArea = max(maxArea, getArea(result[i], result[j]));
            }
        }
        return maxArea;
    }
private:
    inline long long getArea(const vector<int> &a, const vector<int> &b) {
        // x coordinates miss intersection
        if (b[2] <= a[0] || a[2] <= b[0]) return 0;

        // y cordinate missing intersection
        if (a[3] <= b[1] || b[3] <= a[1]) return 0;

        // there is intersection
        int startx = max(a[0], b[0]);
        int starty = max(a[1], b[1]);

        int endx = min(b[2], a[2]);
        int endy = min(a[3], b[3]);

        long long squareside = min(abs(startx-endx), abs(starty-endy));
        return squareside * squareside;
    }
};