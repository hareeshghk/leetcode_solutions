class Solution {
public:
    int countBinarySubstrings(string s) {
        int numzero=0, numone=0, result = 0;
        
        if (s[0] =='0') {
            numzero++;
        } else {
            numone++;
        }
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '0') {
                if (s[i-1] =='0') {
                    numzero++;
                } else {
                    result += min(numzero, numone);
                    numzero = 1;
                }
            } else {
                if (s[i-1] =='1') {
                    numone++;
                } else {
                    result += min(numzero, numone);
                    numone = 1;
                }
            }
        }
        result += min(numzero, numone);
        return result;
    }
};