class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<bool> seen = vector<bool>(26, false);
        vector<vector<int>> counter = vector<vector<int>>(26, vector<int>(26, 0));
        vector<int> solCounter = vector<int>(26, 0);

        int n = s.length();

        for (int i = 0; i < n; ++i) {
            char x = s[i];
            int idx = x-'a';

            if (seen[idx]) {
                solCounter[idx] = GetUniqueCount(counter, idx);
            } else {
                seen[idx] = true;
            }

            for (int i = 0; i < 26; ++i) {
                if (seen[i]) {
                    counter[i][idx]++;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += solCounter[i];
        }
        return ans;
    }
private:
    int GetUniqueCount(vector<vector<int>> &c, int idx) {
        auto x = c[idx];
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (x[i] > 0) {
                if (i == idx) {
                    if (x[i] > 1) ans++;
                } else {
                    ans++;
                }
            }
        }
        return ans;
    }
};

// verey character see if it appeared already then unique chars between current occurence and old occurrence is the count
// 