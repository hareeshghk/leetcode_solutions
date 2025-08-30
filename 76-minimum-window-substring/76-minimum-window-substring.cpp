#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        if (m < n) return "";
        
        unordered_map<char, int> freqmap;
        
        for (auto ch : t) {
            freqmap[ch]++;
        }
        
        int ws = 0;
        int matched = 0;
        int minlength = INT_MAX, start=-1;
        for (int we = 0; we < m; ++we) {
            if (freqmap.find(s[we]) != freqmap.end()) {
                freqmap[s[we]]--;
                if (freqmap[s[we]] == 0) matched++;
            }
            
            while (matched == freqmap.size()) {
                if (we-ws+1 < minlength) {
                    minlength = we-ws+1;
                    start = ws;
                }
                
                if (freqmap.find(s[ws]) != freqmap.end()) {
                    if (freqmap[s[ws]] == 0) matched--;
                    freqmap[s[ws]]++;
                }
                ws++;
            }
        }
        
        return minlength==INT_MAX?"":s.substr(start, minlength);
    }
};
