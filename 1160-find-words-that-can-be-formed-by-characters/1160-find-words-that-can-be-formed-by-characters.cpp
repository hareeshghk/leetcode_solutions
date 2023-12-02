class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        auto counter = vector<int>(26, 0);
        
        for (auto ch : chars) {
            counter[ch-'a']++;
        }
        
        int answer = 0;
        for (auto word : words) {
            auto charCounter = getCount(word);
            bool wordformed = true;
            for (int i = 0; i < 26; ++i) {
                if (charCounter[i] > counter[i]) {
                    wordformed = false;
                    break;
                }
            }
            if (wordformed) answer+=word.length();
        }
        return answer;
    }
    
    vector<int> getCount(const string &w) {
        vector<int> counter = vector<int>(26, 0);
        
        for (auto ch : w) {
            counter[ch-'a']++;
        }
        return counter;
    }
};