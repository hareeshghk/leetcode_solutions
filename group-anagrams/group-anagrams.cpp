#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> anagrammap;
        
        for (auto str :strs) {
            anagrammap[GetCountStr(str)].push_back(str);
        }
        
        vector<vector<string>> result;
        
        for (auto vals : anagrammap) {
            result.push_back(vals.second);
        }
        return result;
    }
    
    string GetCountStr(string &s) {
        vector<int> counts(26, 0);
        
        for (auto ch :s) {
            counts[ch-'a']++;
        }
        
        string result = "";
        for (int i = 0; i < 26; ++i) {
            result += counts[i]+'0';
            result += ",";
        }
        return result;
    }
};
