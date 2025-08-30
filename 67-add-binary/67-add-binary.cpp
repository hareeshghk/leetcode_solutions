#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length()-1;
        int m = b.length()-1;
        
        string ans;
        int x, y, sum, carry = 0;
        while (n >=0 || m>=0) {
            x = n>=0?(a[n]-'0'):0;
            y = m>=0?(b[m]-'0'):0;
            sum = x+y+carry;
            carry = sum/2;;
            sum = sum%2;
            ans += (sum+'0');
            n--;
            m--;
        }
        
        if (carry != 0) {
            ans += carry+'0';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
