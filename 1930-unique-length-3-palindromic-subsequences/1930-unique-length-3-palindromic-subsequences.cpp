#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> firstOccrrence = vector<int>(26, -1);
        vector<int> lastOccrrence = vector<int>(26, -1);
        
        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';
            if (firstOccrrence[curr] == - 1) {
                firstOccrrence[curr] = i;
            }
            
            lastOccrrence[curr] = i;
        }
        
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            // character is never seen.
            if (firstOccrrence[i] == -1) {
                continue;
            }
            
            unordered_set<char> between;
            for (int j = firstOccrrence[i] + 1; j < lastOccrrence[i]; j++) {
                between.insert(s[j]);
            }
            
            ans += between.size();
        }
        
        return ans;
    }
};
