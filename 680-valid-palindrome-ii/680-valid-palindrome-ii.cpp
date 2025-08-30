#include <string>

class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();
        int left = 0, right = n-1;
        bool used = false;
        while (left < right) {
            if (s[left] != s[right]) {
                return checkPolindrome(s, left+1, right)||checkPolindrome(s, left, right-1);
            }
            left++;
            right--;
        }
        return true;
    }
    
    bool checkPolindrome(const string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
