class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        
        int bitPositionMover = 1;
        int counter = 0;
        while (counter <= 15) {
            if (n == bitPositionMover) return true;
            bitPositionMover <<= 2;
            counter++;
        }
        
        return false;
    }
};