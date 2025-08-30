#include <string>
using namespace std;

class Solution {
public:
    string baseNeg2(int n) {
        string result = "";
        
        if (n==0) return "0";
        
        while(n != 0) {
            int remaininder = n%-2;
            n /= -2;
            if (remaininder < 0) {
                remaininder += 2;
                n+=1;
            }
            
            result = to_string(remaininder)+result;
        }
        return result;
    }
};
