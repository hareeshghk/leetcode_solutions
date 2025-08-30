#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int num1idx = num1.size()-1;
        int num2idx = num2.size()-1;
        
        string ans;
        
        int sum, carry = 0, x, y;
        while(num1idx >=0 || num2idx>=0) {
            x = num1idx>=0?(num1[num1idx]-'0'):0;
            y = num2idx>=0?(num2[num2idx]-'0'):0;
            sum =  x+ y+ carry;
            carry = sum/10;
            sum = sum%10;
            
            ans += (char) (sum+'0');
            num1idx--;
            num2idx--;
        }
        
        if (carry != 0) {
            ans += (char) (carry+'0');
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
