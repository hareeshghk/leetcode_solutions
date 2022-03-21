class Solution {
public:
    bool isRobotBounded(string instructions) {
        // directions is 4 use 0,1,2,3
        int direction = 0;
        unordered_map<int, pair<int,int>> dirs {{0, make_pair(0,1)},{1, make_pair(1,0)},{2, make_pair(0,-1)},{3, make_pair(-1,0)}};
        int x=0,y=0;
        for (auto ch : instructions) {
            if (ch == 'G') {
                x += dirs[direction].first;
                y += dirs[direction].second;
            } else if (ch == 'L') {
                direction = (direction-1+4)%4;
            } else {
                direction = (direction + 1)%4;
            }
        }
        
        if (x == 0 && y== 0) return true;
        
        if (direction == 0) return false;
        return true;
    }
};