#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int w = words.size();
        int p = puzzles.size();
        
        vector<int> result(p, 0);
        
        unordered_map<int, int> wordmap;
        
        for (int i = 0; i < w; i++) {
            wordmap[findbitmap(words[i])]++;
        }
        
        int count, bitmap, firstchar;
        
        int idx = 0;
        for (auto puzzle : puzzles) {
            bitmap = findbitmap(puzzle.substr(1));
            firstchar = 1<<(puzzle[0]-'a');
            
            count = wordmap[firstchar];
            
            for (int submask = bitmap; submask; submask = (submask-1)&bitmap) {
                count += wordmap[submask|firstchar];
            }
            result[idx++] = count;
        }
        return result;
    }
    
    int findbitmap(string a) {
        int res =0;
        
        for (int i = 0; i < a.length(); i++) {
            res |=  1<<(a[i]-'a');
        }
        return res;
    }
};
