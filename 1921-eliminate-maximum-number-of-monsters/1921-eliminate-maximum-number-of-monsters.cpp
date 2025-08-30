#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        // convert dist and speed to time when monter reaches position 0 or less
        vector<int> timesToReach;
        for (int i = 0; i < dist.size(); ++i) {
            timesToReach.push_back(ceil((dist[i]*1.0)/speed[i]));
        }
        
        // sort the above values
        sort(timesToReach.begin(), timesToReach.end());
        
        // find first index where index crosses or equals the value crosses the index is answer.
        for (int i = 0; i < timesToReach.size(); ++i) {
            if (i >= timesToReach[i]) return i;
        }
        return timesToReach.size();
    }
};
