class DSU {
    vector<int> parent;
    int size;
public:
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        size = n;
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
        --size;
        
        if (pa<pb) {
            parent[pb] = pa;
        } else {
            parent[pa] = pb;
        }
        return true;
    }
    
    int getSize() {
        return size;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> email_idx_map;
        int n = accounts.size();
        DSU d(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (email_idx_map.find(accounts[i][j]) !=  email_idx_map.end()) {
                    d.unionfind(email_idx_map[accounts[i][j]], i);
                } else {
                    email_idx_map[accounts[i][j]] = i;
                }
            }
        }
        
        unordered_map<int, set<string>> unique_mails;
        for (int i = 0; i < n; i++) {
            int pa = d.find(i);
            if (unique_mails.find(pa) == unique_mails.end()) {
                unique_mails[pa] = set<string>();
            }
            
            for (int j= 1; j < accounts[i].size(); ++j) {
                unique_mails[pa].insert(accounts[i][j]);
            }
        }
        
        vector<vector<string>> result;
        for (auto cur : unique_mails) {
            vector<string> account;
            account.push_back(accounts[cur.first][0]);
            for (auto email : cur.second) {
                account.push_back(email);
            }
            result.push_back(account);
        }
        return result;
    }
};