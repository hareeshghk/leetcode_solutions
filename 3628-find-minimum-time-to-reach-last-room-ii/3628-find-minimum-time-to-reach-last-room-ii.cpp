class node {
public:
    int position;
    int time;
    int turn;
    node(int a, int b, int c) {
        position = a;
        time = b;
        turn = c;
    }
};

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        vector<vector<int>> dirs = {{-1,0},{1, 0}, {0, 1}, {0, -1}};
        auto comp = [](node &a, node &b) {
            return a.time > b.time;
        };
        int n = moveTime.size();
        int m = moveTime[0].size();
        auto pq = priority_queue<node, vector<node>, decltype(comp)>(comp);
        vector<int> timeTaken = vector<int> (n*m, -1);
        timeTaken[0] = 0;
        pq.push(node(0, 0, 1));

        while (!pq.empty()) {
            auto topper = pq.top();
            pq.pop();

            int x= topper.position/m;
            int y = topper.position%m;

            if (x == n-1 && y == m-1) return topper.time;

            for (auto dir : dirs) {
                int neix = x  + dir[0];
                int neiy = y  + dir[1];
                int pos = (neix * m) + neiy;
                if (neix >= 0 && neix < n && neiy >=0 && neiy < m) {
                    int newTime = max(topper.turn + topper.time, topper.turn + moveTime[neix][neiy]);
                    
                    if (timeTaken[pos] == -1 || timeTaken[pos] > newTime) {
                        timeTaken[pos] = newTime;
                        pq.push(node(pos, newTime, 3-(topper.turn)));
                    }
                }
            }
        }
        return -1;
    }
};