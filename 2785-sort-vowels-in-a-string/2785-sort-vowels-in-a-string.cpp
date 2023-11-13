class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<char> vsInS;
        vector<int> indices;
        for (int i = 0; i < s.size(); ++i) {
            if (vowels.find(s[i]) != vowels.end()) {
                vsInS.push_back(s[i]);
                indices.push_back(i);
            }
        }
        
        sort(vsInS.begin(), vsInS.end());
        
        for (int i = 0; i < indices.size(); ++i) {
            s[indices[i]] =vsInS[i];
        }
        return s;
    }
};