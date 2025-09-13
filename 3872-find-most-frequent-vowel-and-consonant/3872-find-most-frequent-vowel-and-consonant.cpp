class Solution {
public:
    int maxFreqSum(string s) {
        // a to z, we can store count in a 26 size vector.
        vector<int> counter = vector<int>(26, 0);

        for (char c : s) {
            counter[c-'a']++;
        }

        int maxVowelFreq = 0;
        int maxConsonantFreq = 0;

        unordered_set<int> vowelSet = unordered_set<int>{0, 'e'-'a', 'i'-'a', 'o'-'a', 'u'-'a'};
        for (int i = 0; i < 26; ++i) {
            if (vowelSet.find(i) != vowelSet.end()) {
                maxVowelFreq = max(maxVowelFreq, counter[i]);
            } else {
                maxConsonantFreq = max(maxConsonantFreq, counter[i]);
            }
        }

        return maxVowelFreq + maxConsonantFreq;
    }
};