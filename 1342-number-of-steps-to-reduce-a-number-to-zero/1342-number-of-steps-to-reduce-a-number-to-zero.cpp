class Solution {
public:
    int numberOfSteps(int num) {
        int result = 0;
        
        while (num!=0) {
            if (num&1) {
                result++;
            }
            
            num>>=1;
            
            ++result;
        }
        return max(0,result-1);
    }
};