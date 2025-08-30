#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

class DSU {
    vector<int> parents, sizes;
public:
    DSU() {
        parents.resize(20, 0);
        sizes.resize(20, 1);
        for (int i = 0; i < 20 ; i++) {
            parents[i] = i;
        }
    }
    
    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    
    bool unionize(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) return false;
        if (sizes[pa] > sizes[pb]) {
            parents[pb] = pa;
            sizes[pa] += sizes[pb];
        } else {
            parents[pa] = pb;
            sizes[pb] += sizes[pa];
        }
        return true;
    }
    
    unordered_map<int, set<string>> getList(unordered_map<int,string> &revwordmap) {
        unordered_map<int, set<string>> result;
        for (int i = 0; i < 20; ++i) {
            if (parents[i] == i) {
                result[i] = set<string>();
            }
        }
        
        for (int i = 0; i < 20; ++i) {
            if (revwordmap.find(i) == revwordmap.end()) continue;
            result[find(i)].insert(revwordmap[i]);
        }
        
        return result;
    }
};

class Solution {
public:
    vector<string> result;
    unordered_map<string,int> wordmap;
    unordered_map<int, set<string>> mappings;
    DSU disjoint_sets;
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        int counter = 0;
        unordered_map<int,string> revwordmap;
        for (auto s : synonyms) {
            if (wordmap.find(s[0]) == wordmap.end()) {
                revwordmap[counter] = s[0];
                wordmap[s[0]] = counter++;
            }
            if (wordmap.find(s[1]) == wordmap.end()) {
                revwordmap[counter] = s[1];
                wordmap[s[1]] = counter++;
            }
            disjoint_sets.unionize(wordmap[s[0]], wordmap[s[1]]);
        }
        
        // for every parent lets have a set of strings.
        mappings = disjoint_sets.getList(revwordmap);
        
        recurse(0, text, "");
        
        return result;
    }
    
    void recurse(int idx, string text, string curstring) {
        if (idx >= text.length()) {
            result.push_back(curstring);
            return;
        }
        int j = idx;
        while (idx < text.length() && text[idx] != ' ') idx++;
        string word = text.substr(j, idx-j);
        if (wordmap.find(word) == wordmap.end()) {
            if (idx == text.length()) {
                recurse(idx+1, text, curstring+word);
            } else {
                recurse(idx+1, text, curstring+word+" ");
            }
        } else {
            auto &curset = mappings[disjoint_sets.find(wordmap[word])];
            for (auto str : curset) {
                if (idx == text.length()) {
                    recurse(idx+1, text, curstring+str);
                } else {
                    recurse(idx+1, text, curstring+str+" ");
                }
            }
        }
    }
};
