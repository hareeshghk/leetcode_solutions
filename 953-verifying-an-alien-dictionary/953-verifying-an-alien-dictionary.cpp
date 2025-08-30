#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> val;
        int counter = 0;
        
        for (auto ch : order) {
            val[ch] = counter;
            ++counter;
        }
        
        for (int i =1; i < words.size(); ++i) {
            string w1 = words[i-1];
            string w2 = words[i];
            
            bool valid = false;
            for (int j = 0; j < min(w1.length(), w2.length()); ++j) {
                if (val[w1[j]] > val[w2[j]]) {
                    return false;
                } else if (val[w1[j]] < val[w2[j]]) {
                    valid = true;
                    break;
                }
            }
            
            if (!valid && w1.length() > w2.length()) {
                return false;
            }
        }
        return true;
    }
};
