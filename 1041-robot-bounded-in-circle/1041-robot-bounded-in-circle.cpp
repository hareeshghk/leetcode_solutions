class Solution {
public:
    bool isRobotBounded(string instructions) {
        // directions is 4 use 0,1,2,3
        int dx = 0, dy = 1;
        int x = 0, y = 0;
        for (auto ch : instructions) {
            if (ch == 'G') {
                x += dx;
                y += dy;
            } else if (ch == 'L') {
                swap(dx,dy);
                dx = -dx;
            } else {
                swap(dx,dy);
                dy = -dy;
            }
        }
        
        if (x == 0 && y== 0) return true;
        
        if (dx == 0 && dy == 1) return false;
        return true;
    }
};