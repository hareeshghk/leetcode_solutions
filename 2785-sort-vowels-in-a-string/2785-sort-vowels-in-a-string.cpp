#include <algorithm>
#include <map>
#include <string>
#include <vector>

class Solution {
public:
    string sortVowels(string s) {
        map<char, int> vowels {{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}, {'A', 0}, {'E', 0}, {'I', 0}, {'O', 0}, {'U', 0}};
        vector<int> indices;
        for (int i = 0; i < s.size(); ++i) {
            if (vowels.find(s[i]) != vowels.end()) {
                vowels[s[i]]++;
                indices.push_back(i);
            }
        }
        
        auto iter = vowels.begin();
        
        for (int i = 0; i < indices.size(); ++i) {
            while (iter->second == 0) {
                iter++;
            }
            s[indices[i]] = iter->first;
            iter->second--;
        }
        return s;
    }
};
