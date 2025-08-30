#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int word_len = word.length();
        
        int maxLen = 0;
        int windowStart = 0;
        int vowelCount = 4;
        for (int windowEnd = 1;windowEnd < word_len; ++windowEnd) {
            if (word[windowEnd] < word[windowEnd-1]) {
                windowStart = windowEnd;
                vowelCount = 4;
            } else {
                if (word[windowEnd] != word[windowEnd-1]) vowelCount--;
            }
            
            if (vowelCount == 0) maxLen = max(maxLen, windowEnd-windowStart+1);
        }
        return maxLen;
    }
};
