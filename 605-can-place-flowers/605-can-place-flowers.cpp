#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int possiblePlaces = 0;
        int start=-2, idx = 0;
        int flowerbedsize = flowerbed.size();
        while (idx < flowerbedsize) {
            if (flowerbed[idx] == 1) {
                int num_slots = idx-1-start;
                
                possiblePlaces += max(0, (num_slots-1)/2);
                
                start = idx;
            }
            ++idx;
        }
        
        int num_slots = idx-1-start;
                
        possiblePlaces += max(0, (num_slots)/2);

        return (possiblePlaces>=n);
    }
};
