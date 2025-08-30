#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class DSU {
    vector<int> parent;
    int c;
    int groups;
public:
    DSU(int n) {
        c = n;
        groups = n;
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unionfind(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa == pb) return false;
        parent[pb] = pa;
        --groups;
        return true;
    }
    int getgroups() {
        return groups;
    }
};

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DSU d(n);
        
        
        for (int i = 0; i < n; i++) {
            for (int j = i-1; j >= 0; --j) {
                if (isequivalent(strs[i], strs[j])) {
                    d.unionfind(i, j);
                }
            }
        }
        return d.getgroups();
    }
    
    bool isequivalent(string &a, string &b) {
        int k = a.length();
        int count = 0;
        for (int i = 0; i < k; ++i) {
            if (a[i] != b[i]) ++count;
            if (count > 2) return false;
        }
        return (count==2||count==0);
    }
};
