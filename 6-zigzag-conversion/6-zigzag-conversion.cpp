#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string ans ="";
        int n =s.length();
        
        if (numRows == 1 || n==0) return s;
        
        // first row
        int j = 0;
        while (j < n) {
            ans += s[j];
            j = j + 2*(numRows-1);
        }
        
        // middle rows
        for (int i =1; i < numRows-1;i++) {
            int j = i;
            while (j < n) {
                ans += s[j];
                if (j+2*(numRows-i-1) < n)
                    ans += s[j+2*(numRows-i-1)];
                j = j + 2*(numRows - 1);
            }
        }
        
        //last row
        j = numRows-1;
        while (j < n) {
            ans += s[j];
            j = j + 2*(numRows-1);
        }
        
        return ans;
    }
};
