#include <string>

class Solution {
public:
    string largestOddNumber(string num) {
        int len = num.length();
        
        int j = len-1;
        
        while (j >= 0) {
            if ((num[j]-'0') &1) break;
            j--;
        }
        
        return num.substr(0, j+1);
    }
};
