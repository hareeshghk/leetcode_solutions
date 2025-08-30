#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_set<char> uniqueletters;
        for (auto ch : s) {
            uniqueletters.insert(ch);
        }
        
        int totaluniqueletters = uniqueletters.size();
        int result = 0;
        for (int maxunique = 1; maxunique <= totaluniqueletters; ++maxunique) {
            vector<int> freq(26, 0);
            int ws = 0;
            int curunique = 0, curvalid = 0;
            for (int we =0; we < s.length(); ++we) {
                if (freq[s[we]-'a'] == 0) {
                    curunique++;
                }
                freq[s[we]-'a']++;
                if (freq[s[we]-'a'] == k) curvalid++;
                
                while (curunique > maxunique) {
                    freq[s[ws]-'a']--;
                    if (freq[s[ws]-'a'] == 0) curunique--;
                    if(freq[s[ws]-'a'] == k-1) curvalid--;
                    ws++;
                }
                
                if(curunique == curvalid) {
                    result = max(result, we-ws+1);
                }
            }
        }
        return result;
    }
};
