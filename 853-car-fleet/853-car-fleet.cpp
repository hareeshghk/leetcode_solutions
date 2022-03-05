class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        map<int, double> pos_time_map;
        
        for (int i = 0; i < n; ++i) {
            pos_time_map[-position[i]] = ((target-position[i])*1.0)/speed[i];
        }
        
        int ans = 0;
        double curtime = 0;
        for (auto it : pos_time_map) {
            if (it.second > curtime) {
                curtime = it.second;
                ans++;
            }
        }
        return ans;
    }
};