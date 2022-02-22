class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // I wante ording so using map otherwoise unorderedmap
        map<int, int> adders;
        for (auto trip:trips) {
            if (adders.find(trip[1]) == adders.end()) adders[trip[1]] = 0;
            adders[trip[1]] += trip[0];
            if (adders.find(trip[2]) == adders.end()) adders[trip[2]] = 0;
            adders[trip[2]] -= trip[0];
        }
        
        int current_capacity = 0;
        for (auto val : adders) {
            current_capacity += val.second;
            if (current_capacity > capacity)
                return false;
        }
        return true;
    }
};