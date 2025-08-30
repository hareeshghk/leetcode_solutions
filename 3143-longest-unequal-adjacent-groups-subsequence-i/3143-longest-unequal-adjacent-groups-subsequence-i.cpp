#include <string>
#include <vector>

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        // First can be 0 or 1.
        int n = words.size();

        int currentGroup = groups[0];
        int currentMaxIndex = -1;
        int currentMaxSize = 0;

        vector<string> answer;

        for (int i = 0; i < n; ++i) {
            if (groups[i] == currentGroup) {
                if (words[i].length() > currentMaxSize) {
                    currentMaxIndex = i;
                    currentMaxSize = words[i].length();
                }
            } else {
                answer.push_back(words[currentMaxIndex]);
                currentGroup = groups[i];
                currentMaxIndex = i;
                currentMaxSize = words[i].length();
            }
        }
        if (currentMaxIndex != -1) answer.push_back(words[currentMaxIndex]);

        return answer;
    }
};
