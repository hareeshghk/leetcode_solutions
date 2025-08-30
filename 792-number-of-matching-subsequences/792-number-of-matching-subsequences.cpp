#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> mp(26, vector<int>(0));
        
        for (int i = 0; i < s.length(); i++) {
            mp[(s[i]-'a')].push_back(i);
        }

        int result = 0;
        
        for (auto word : words) {
            int i = 0;
            int prev = -1;
            while (i < word.length()) {
                int cur = word[i]-'a';
                auto itr = upper_bound(mp[cur].begin(), mp[cur].end(), prev);
                if (itr == mp[cur].end()) {
                    break;
                }
                prev = *itr;
                i++;
            }
            if (i == word.length()) result++;
        }
        return result;
    }
};
