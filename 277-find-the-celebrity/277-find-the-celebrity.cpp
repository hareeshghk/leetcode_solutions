#include <algorithm>
#include <map>
#include <utility>

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
    map<pair<int,int>, bool> myknows_map;
public:
    bool myknow(int i, int j) {
        auto p = pair<int,int>(i, j);
        if (myknows_map.find(p) == myknows_map.end()) {
            myknows_map[p] = knows(i, j);
        }
        return myknows_map[p];
    }
    
    int findCelebrity(int n) {
        int candidate = 0;
        
        for (int i = 0; i < n; ++i) {
            if (knows(candidate, i)) {
                candidate = i;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (i== candidate) continue;
            if (!knows(i, candidate) || knows(candidate, i)) return -1;
        }
        
        return candidate;
    }
};
