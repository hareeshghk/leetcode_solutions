#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> chosenChars;
        int chosenCharsSize = 0;
        
        for (auto val : num) {
            while (chosenCharsSize != 0 && (chosenChars[chosenCharsSize-1]-'0' > val-'0') && k>0) {
                chosenChars.pop_back();
                --chosenCharsSize;
                k--;
            }
            chosenChars.push_back(val);
            ++chosenCharsSize;
        }
        
        for (int i = 0; i < k; i++) {
            if (chosenCharsSize == 0) break;
            chosenChars.pop_back();
            --chosenCharsSize;
        }
        
        string ans;
        bool leadingzero = true;
        
        for (int i = 0; i < chosenCharsSize; ++i) {
            if (leadingzero && chosenChars[i] == '0') {
                continue;
            }
            leadingzero = false;
            ans += chosenChars[i];
        }
        
        if(ans == "") return "0";
        
        return ans;
    }
};
