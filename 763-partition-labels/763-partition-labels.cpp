#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26, 0);
        unordered_set<char> seen;
        
        for (auto ch : s) {
            freq[ch-'a']++;
        }
        
        int n = s.length();
        int start = 0;
        int zeroedcount = 0;
        vector<int> result;
        for (int i = 0; i < n; i++) {
            seen.insert(s[i]);
            freq[s[i]-'a']--;
            if (freq[s[i]-'a'] == 0) {
                zeroedcount++;
            }
            if (zeroedcount == seen.size()) {
                result.push_back(i-start+1);
                start = i+1;
            }
        }
        
        return result;
    }
};
