#include <algorithm>
#include <vector>

class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long int allsum = 0;
        int n = enemyEnergies.size();
        int minimumVal = INT_MAX;
        for (auto e : enemyEnergies) {
            minimumVal = min(minimumVal, e);
            allsum += e;
        }

        if (currentEnergy < minimumVal) return 0;

        long long energyAccumulated = (allsum + currentEnergy) - (2* minimumVal); 

        return 1 + (energyAccumulated/minimumVal);
    }
};
