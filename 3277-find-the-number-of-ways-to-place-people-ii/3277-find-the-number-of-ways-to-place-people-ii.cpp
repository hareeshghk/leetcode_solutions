class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // sorting which n log n
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) {
            if (a[0] < b[0]) {
                return true;
            } else if (a[0] == b[0] && a[1] > b[1]) {
                return true;
            } else {
                return false;
            }
        });

        // iterate through the points for alice position
        // each position try to fetch all the possibilities for bobs location and added them to solution.
        // n*2
        int n = points.size();
        int answer = 0;
        for (int alicePos = 0; alicePos < n-1; ++alicePos) {
            int bobPos = alicePos + 1;
            int minYCordinate = INT_MIN;
            int maxYCordinate = points[alicePos][1] + 1;
            while (bobPos < n) {
                if (points[bobPos][1] > minYCordinate && points[bobPos][1] < maxYCordinate) {
                    answer++;
                }

                if (points[bobPos][1] < maxYCordinate) {
                    minYCordinate = max(minYCordinate, points[bobPos][1]);
                }
                bobPos++;
            }
        }

        return answer;
    }
};