class Solution {
public:
    int maxwordsize;
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset;
        maxwordsize = 0;
        for (auto word : wordDict) {
            maxwordsize = max(maxwordsize, (int)word.length());
            wordset.insert(word);
        }
        dp.resize(s.length(), -1);
        return isPosible(s, 0, wordset);
    }
    
    vector<int> dp;
    bool isPosible(string &s, int start, unordered_set<string> &wordset) {
        if (start == s.length()) return true;
        
        if (dp[start] != -1) {
            return dp[start]==0?false:true;
        }
        
        for (int i = 1; i <= maxwordsize; i++) {
            string cur = s.substr(start, i);
            if (wordset.count(cur) != 0) {
                if (isPosible(s, start+i, wordset)) {
                    dp[start] = 1;
                    return true;
                }
            }
        }
        dp[start] = 0;
        return false;
    }
};