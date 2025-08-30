#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto version1_tokens = GetTokens(version1);
        auto version2_tokens = GetTokens(version2);
        
        
        // for (auto tok : version1_tokens) {
        //     cout << tok << " ";
        // }
        // cout << endl;
        
        for (int i = 0; i < min(version1_tokens.size(), version2_tokens.size()); ++i) {
            if (version1_tokens[i] < version2_tokens[i]) {
                return -1;
            } else if (version1_tokens[i] > version2_tokens[i]) {
                return 1;
            }
        }
        
        if (version1_tokens.size() > version2_tokens.size()) {
            int k = version2_tokens.size();
            while (k < version1_tokens.size()) {
                if (version1_tokens[k] != 0) return 1;
                ++k;
            }
        }
        
        if (version2_tokens.size() > version1_tokens.size()) {
            int k = version1_tokens.size();
            while (k < version2_tokens.size()) {
                if (version2_tokens[k] != 0) return -1;
                ++k;
            }
        }
        
        return 0;
    }
    
    vector<int> GetTokens(string &s) {
        vector<int> result;
        int start=0,end=0;
        for (start=s.find_first_not_of('.', end);start != string::npos;) {
            end = s.find('.', start);
            result.push_back(stoi(s.substr(start, end-start)));
            start = s.find_first_not_of('.', end);
        }
        return result;
    }
};
