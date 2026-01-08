class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        return false;
    }

private:
    bool isMyStrictlyPalindromic(int n) {
        for (int base = 2; base <= n-2; ++base) {
            if (!isPolindrome(n, base)) return false;
        }
        return true;
    }
    bool isPolindrome(int n, int b) {
        vector<int> representation;
        while (n!=0) {
            representation.push_back(n%b);
            n /= b;
        }

        int left = 0, right = representation.size()-1;

        while (left < right) {
            if (representation[left] != representation[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};