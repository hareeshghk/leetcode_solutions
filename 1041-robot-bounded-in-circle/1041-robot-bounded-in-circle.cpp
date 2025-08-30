#include <string>
using namespace std;

class Solution {
public:
    bool isRobotBounded(string instructions) {
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
