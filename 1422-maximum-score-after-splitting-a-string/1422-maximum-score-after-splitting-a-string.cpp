#include <algorithm>
#include <string>

class Solution {
public:
    int maxScore(string s) {
        int score  = 0;
        int numzeroes = 0;
        for (int i = 0; i < s.length()-1; ++i) {
            if (s[i] == '0') ++numzeroes;
            score = max(score, 2*numzeroes-i);
        }
        
        if (s[s.length()-1] == '0') {
            ++numzeroes;
        }
        
        return score + (s.length()-1 - numzeroes);
    }
};
