#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int wordbitmap, negbitmap, wordlen, result = 0;
        unordered_map<int, int> bitmaptolength;
        for (auto word : words) {
            wordbitmap = 0;
            wordlen = word.length();
            for (auto ch :  word) {
                wordbitmap |= 1 << (ch-'a');
            }
            negbitmap = ~wordbitmap;
            int mask = negbitmap;
            // while (negbitmap != 0) {
            //     if (bitmaptolength.find(negbitmap) != bitmaptolength.end()) {
            //         result = max(result, bitmaptolength[negbitmap]*wordlen);
            //     }
            //     negbitmap = (negbitmap-1)&mask;
            // }
            for (auto val : bitmaptolength) {
                if ((val.first & wordbitmap) == 0) {
                    result = max(result, val.second * (int)word.length());
                }
            }
            if (bitmaptolength.find(wordbitmap) == bitmaptolength.end()) {
                bitmaptolength[wordbitmap] = word.length();
            } else {
                bitmaptolength[wordbitmap] = max(bitmaptolength[wordbitmap], wordlen);
            }
        }
        return result;
    }
};
