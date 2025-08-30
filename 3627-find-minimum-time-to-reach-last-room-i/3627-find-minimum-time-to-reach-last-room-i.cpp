#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        // timetorach[i][j] = max(1+min(timetoreach[i-1][j],timetoreach[i+1][j],timetoreach[i][j-1],timetoreach[i][j+1])
        // dijikistra with edge weight 1 and also time limit.

        int n = moveTime.size();
        int m = moveTime[0].size();
        // time takes
        vector<int> timeTaken = vector<int>(n*m, -1);
        // minheap
        auto pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>();
        // first point assuming [0][0] is always a zero
        timeTaken[0] = 0;
        pq.push({0, 0});

        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while (!pq.empty()) {
            auto topper = pq.top();
            pq.pop();

            int time = topper.first;
            int x = topper.second / m;
            int y = topper.second % m;

            if (x == n-1 && y == m-1) {
                return time;
            }

            for (auto dir : dirs) {
                int neix = x + dir[0];
                int neiy = y + dir[1];
                int pos = (neix * m) + neiy;
                if (neix >= 0 && neix < n && neiy >= 0 && neiy < m) {
                    int neitime = max(1 + time, 1 + moveTime[neix][neiy]);

                    if (timeTaken[pos] == -1 || timeTaken[pos] >  neitime) {
                        timeTaken[pos] = neitime;
                        pq.push({neitime, pos});
                    }
                }
            }
        }

        return -1;
    }
};
