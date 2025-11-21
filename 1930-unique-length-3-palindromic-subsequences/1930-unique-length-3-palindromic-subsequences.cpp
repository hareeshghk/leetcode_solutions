class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<bool> seen = vector<bool>(26, false);
        vector<int> counter = vector<int>(26, 0);
        vector<int> solCounter = vector<int>(26, 0);

        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int idx = s[i]-'a';

            if (seen[idx]) {
                solCounter[idx] = GetUniqueCount(counter[idx]);
            }

            for (int i = 0; i < 26; ++i) {
                if (seen[i]) {
                    counter[i] = (counter[i] | (1<<idx));
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
    int GetUniqueCount(int idx) {
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (idx & 1) ans++;
            idx = idx>>1;
        }
        return ans;
    }
};

// verey character see if it appeared already then unique chars between current occurence and old occurrence is the count
// 