class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        // dp problem
        // every wrod in sequence maintain max seq possible with that word and its previoud index.

        int n = words.size();

        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(2, -1));
        int maxLength = 0;
        int maxLengthIndex = -1;
        for (int i = n-1; i >= 0; --i) {
            int wordlen = words[i].length();
            dp[i] = {1, n};

            // instead of for loop we cna generate all strings in hamming distance one from ith string and serach
            // for them in a unordered map created form seen string as per i for loop.
            for (int j = i+1; j < n; ++j) {
                if (groups[i] != groups[j] && inhammingdistance(words[i], words[j])) {
                    if (dp[i][0] < dp[j][0] + 1) {
                        dp[i] = {dp[j][0] + 1, j};
                    }
                }
            }
            if (dp[i][0] > maxLength) {
                maxLength = dp[i][0];
                maxLengthIndex = i;
            }
        }

        vector<string> answer = vector<string>();

        while (maxLengthIndex != n) {
            answer.push_back(words[maxLengthIndex]);
            maxLengthIndex = dp[maxLengthIndex][1];
        }

        return answer;
    }
private:
    bool inhammingdistance(string &a, string &b) {
        int diff = 0;
        int alen = a.length();
        int blen = b.length();

        if (alen != blen) return false;
        
        for (int i = 0; i < alen; ++i) {
            if (a[i] != b[i]) {
                diff++;
            }
            if (diff > 1) return false;
        }

        return (diff == 1);
    }
};