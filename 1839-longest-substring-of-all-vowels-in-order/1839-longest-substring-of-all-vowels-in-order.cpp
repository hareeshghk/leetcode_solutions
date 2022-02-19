class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int word_len = word.length();
        
        int maxLen = 0;
        int windowStart = 0;
        int vowelCount = 5;
        for (int windowEnd = 1;windowEnd < word_len; ++windowEnd) {
            if (word[windowEnd] < word[windowEnd-1]) {
                windowStart = windowEnd;
                vowelCount = 5;
            } else {
                if (word[windowEnd] != word[windowEnd-1]) vowelCount--;
            }
            
            if (vowelCount == 1) maxLen = max(maxLen, windowEnd-windowStart+1);
        }
        return maxLen;
    }
};