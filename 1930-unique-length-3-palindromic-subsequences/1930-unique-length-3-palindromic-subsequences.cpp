class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<bool> seen = vector<bool>(26, false);
        vector<int> counter = vector<int>(26, 0);
        vector<int> solCounter = vector<int>(26, 0);

        vector<int> bits = vector<int>(26, 0);
        bits[0]=1;
        for (int i = 1; i < 26; ++i) {
            bits[i] = bits[i-1]<<1;
        }

        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int idx = s[i]-'a';

            if (seen[idx]) {
                solCounter[idx] = GetUniqueCount(counter[idx]);
            }

            for (int i = 0; i < 26; ++i) {
                if (seen[i]) {
                    counter[i] = (counter[i] | (bits[idx]));
                }
            }

            seen[idx] = true;
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += solCounter[i];
        }
        return ans;
    }
private:
    inline int GetUniqueCount(int n) {
        int count = 0;
        while (n > 0) {
            n &= (n - 1); // This unsets the rightmost set bit
            count++;
        }
        return count;
    }
};