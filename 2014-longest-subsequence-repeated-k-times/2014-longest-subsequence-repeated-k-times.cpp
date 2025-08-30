#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<char> chosen;
        unordered_map<char, int> freq;
        for (int i = 0; i < s.length(); ++i) {
            freq[s[i]]++;
        }
        
        for (auto val : freq) {
            if (val.second >= k) {
                chosen.push_back(val.first);
            }
        }
        
        sort(chosen.begin(), chosen.end());
        
        queue<string> valid;
        valid.push("");
        string ans = "";
        while (!valid.empty()) {
            auto cur = valid.front();
            valid.pop();
            if (cur.length() == 7) continue;
            string modified;
            for (int i = 0; i < chosen.size(); ++i) {
                modified = cur+chosen[i];
                if (ispossible(modified, s, k)) {
                    ans = modified;
                    valid.push(modified);
                }
            }
        }
        return ans;
    }
    
    bool ispossible(string &m, string &s, int k) {
        int count = 0;
        int j = 0, l = m.length();;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == m[j]) {
                j++;
                if(j == l) {
                    j = 0;
                    count++;
                    if(count == k) return true;
                }
            }
        }
        return false;
    }
};
