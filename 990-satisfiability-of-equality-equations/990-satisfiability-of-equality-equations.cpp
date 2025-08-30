#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class DSU {
    vector<int> parent;
public:
    DSU() {
        parent.resize(26);
        for (int i = 0; i < 26; i++) parent[i] = i;
    }
    
    int find(int a) {
        if(parent[a] != a) {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }
    
    bool unionfind(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if(pa == pb) return false;
        if (pa < pb) parent[pb] = pa;
        else parent[pa] = pb;
        return true;
    }
    
    bool isconnected(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        return pa==pb;
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DSU equal, notequal;
        char a, b;
        int pa, pb;

        for (auto equation : equations) {
            if (equation[1] == '=') {
                equal.unionfind(equation[0]-'a', equation[3]-'a');
            }
        }
        
        for (auto equation : equations) {
            if (equation[1] == '!') {
                pa = equal.find(equation[0]-'a');
                pb = equal.find(equation[3]-'a');
                if (pa == pb) return false;
            }
        }
        
        return true;
    }
};
