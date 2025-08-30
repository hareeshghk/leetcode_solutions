#include <string>
#include <unordered_set>

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> js;
        
        for (auto ch : jewels) {
            js.insert(ch);
        }
        
        int result = 0;
        
        for (auto ch : stones) {
            if (js.count(ch) != 0) ++result;
        }
        return result;
    }
};
