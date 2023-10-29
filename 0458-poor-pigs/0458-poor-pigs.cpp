class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        if (buckets == 1) return 0;
        int numTurns = minutesToTest/minutesToDie;
        
        // I can take numTurns+1 elements in each dimesnion, I need number of dimensions so
        // that (numTurns+1)^dimensions is greater than or equal to buckets.
        
        // num pigs ranges from 1 to buckets size.
        
        
        int val = numTurns + 1;
        int runningVal = val;
        int pigs = 1;
        
        while (runningVal < buckets) {
            pigs++;
            runningVal *=val;
        }
        
        
        return pigs;
    }
};