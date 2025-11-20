class Solution {
public:
    bool isPalindrome(int x) {
        if ( x < 0 ) return false;
        if (x == 0) return true;

        vector<int> digits;
        while (x != 0) {
            digits.push_back(x%10);
            x/=10;
        }

        int left = 0, right = digits.size()-1;

        while (left < right) {
            if (digits[left] != digits[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};