#include <algorithm>
#include <cctype>
#include <string>

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result = "";
        
        int count  = 0;
        for (int i = s.length()-1; i >=0; --i) {
            if (s[i] == '-') continue;
            
            result += toupper(s[i]);
            ++count;
            
            if (count == k) {
                result += "-";
                count = 0;
            }
        }
        
        reverse(result.begin(), result.end());
        
        if (result == "") return result;
        
        return result.substr(result.find_first_not_of('-', 0));
    }
};
