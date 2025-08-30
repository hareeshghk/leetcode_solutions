#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
    unordered_set<int> cols, ddig, udig;
    vector<vector<string>> ans;
    vector<string> cur;
    vector<vector<string>> solveNQueens(int n) {
        cur.resize(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cur[i].push_back('.');
            }
        }
        
        solve(0, n);
        return ans;
    }
    
    void solve(int row, int n) {
        if (row == n) {
            ans.push_back(cur);
            return;
        }
        
        int x, y;
        for (int col = 0; col < n; ++col) {
            x = row; y = col;
            if(cols.find(y) == cols.end() &&
              ddig.find(x-y) == ddig.end() &&
              udig.find(x+y) == udig.end()) {
                cur[x][y] = 'Q';
                cols.insert(y);
                ddig.insert(x-y);
                udig.insert(x+y);
                solve(row+1, n);
                cur[x][y] = '.';
                cols.erase(y);
                ddig.erase(x-y);
                udig.erase(x+y);
            }
        }
    }
};
