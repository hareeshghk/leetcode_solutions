class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        
        // if (n & 1) return false;
        
        int numEvenBitsOn {0};
        int numOddBitsOn {0};
        
        int bitPositionMover = 1;
        int counter = 0;
        while (counter < 31) {
            if ((n & bitPositionMover) != 0) {
                if (counter & 1) {
                    numOddBitsOn++;
                } else {
                    numEvenBitsOn++;
                }
            }
            bitPositionMover <<=1;
            counter++;
        }
        if (numOddBitsOn > 0) return false;
        
        if (numEvenBitsOn == 1) return true;
        
        return false;
    }
};