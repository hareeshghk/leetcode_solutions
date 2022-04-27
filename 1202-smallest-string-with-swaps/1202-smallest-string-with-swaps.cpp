class DSU {
    vector<int> parents;
    vector<int> rank;
    int n;
public:
    DSU(int n) {
        this->n = n;
        parents.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
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
        
        if (pa==pb) return false;
        
        if (rank[pb] < rank[pa]) {
            parents[pb] = pa;
            rank[pa] += rank[pb];
        } else {
            parents[pa] = pb;
            rank[pb] += rank[pa];
        }
        return true;
    }
    
    // vector<int> GetAllNodes(int p) {
    //     vector<int> result;
    //     for (int i = 0; i < n; ++i) {
    //         if(find(i) == p) {
    //             result.push_back(i);
    //         }
    //     }
    //     return result;
    // }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        
        vector<int> parents(n, 0);
        
        for (int i = 0; i < n; i++) {
            parents[i] = i;
        }
        
        DSU d(n);
        
        for (auto pair : pairs) {
            d.unionize(pair[0], pair[1]);
        }
        
        unordered_map<int,vector<int>> components;
        for (int i = 0; i < n; ++i) {
            components[d.find(i)].push_back(i);
        }
        
        for (auto comp : components) {
            string curstr="";
            for (auto idx : comp.second) {
                curstr += s[idx];
            }
            
            sort(curstr.begin(), curstr.end());
            
            for (int i = 0; i < comp.second.size(); ++i) {
                s[comp.second[i]] = curstr[i];
            }
        }
        
        return s;
    }
    
//     void SortStr(string &s, const vector<int> &pos, int left, int right) {
//         if (left >= right) return;
        
//         int wall = left, pivot = right;
        
//         for (int i = left; i < right; ++i) {
//             if (s[pos[i]] <= s[pos[pivot]]) {
//                 swap(s[pos[i]], s[pos[wall]]);
//                 ++wall;
//             }
//         }
//         swap(s[pos[wall]], s[pos[pivot]]);
//         SortStr(s, pos, left, wall-1);
//         SortStr(s, pos, wall+1, right);
//     }
};