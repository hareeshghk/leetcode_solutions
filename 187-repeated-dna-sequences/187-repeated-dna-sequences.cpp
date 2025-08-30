#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        vector<string> result;
        if (n < 10) return result;
        
        int hash = 0;
        unordered_map<char, int> translate {{'A',0},{'C',1},{'G',2},{'T',3}};
        unordered_set<int> seen, sent;
        for (int i = 0; i < 10; i++) {
            hash = hash*4 + translate[s[i]];
        }
        seen.insert(hash);
        
        int leftmost = 1 << 18;
        for (int i = 10; i < s.length(); i++) {
            hash = (hash - translate[s[i-10]]*leftmost)*4 + translate[s[i]];
            if (seen.find(hash) != seen.end()) {
                if (sent.find(hash) == sent.end()) {
                    result.push_back(s.substr(i-9, 10));
                    sent.insert(hash);
                }
            }
            seen.insert(hash);
        }
        return result;
    }
};
