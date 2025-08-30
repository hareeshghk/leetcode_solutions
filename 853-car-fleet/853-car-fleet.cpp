#include <algorithm>
#include <map>
#include <vector>

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        map<int, double> pos_time_map;
        
        for (int i = 0; i < n; ++i) {
            // using map with negative pos so map will keep them in sort order.
            pos_time_map[-position[i]] = ((target-position[i])*1.0)/speed[i];
        }
        
        // every time a new slow member is choosen we are essentially choosing a new fleet
        // because its a bottle neck for previous cars.
        int ans = 0;
        // assuming nth(our cars are from 0 to n-1) car default case as car takes 0 time to reach target.
        double curtime = 0;
        for (auto it : pos_time_map) {
            // if we get a new slow car then that will be bottle neck for previous people.
            // sp update with slow car't time every time, slow care means more time.
            if (it.second > curtime) {
                curtime = it.second;
                ans++;
            }
        }
        return ans;
    }
};
