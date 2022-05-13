class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> s;
        stations.push_back({target,0});
        int ans = 0, n=stations.size();
        for (int i = 0;i<n;i++) {
            if (startFuel-stations[i][0] < 0) {
                if (s.size()==0) return -1;
                while (s.size()>0 && startFuel-stations[i][0]<0) {
                    startFuel += s.top();
                    s.pop();
                    ans++;
                }
                if (startFuel-stations[i][0]<0) return -1;
            }
            s.push(stations[i][1]);
        }
        return ans;
    }
};