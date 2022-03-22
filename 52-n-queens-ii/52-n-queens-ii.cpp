class Solution {
public:
    int ans;
    unordered_set<int> cols,ddig,udig;
    int totalNQueens(int n) {
        ans=0;
        recurse(0, n);
        return ans;
    }
    
    void recurse(int row, int n) {
        if(row == n) {
            ans++;
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (cols.find(col) != cols.end() ||
               ddig.find(row-col) != ddig.end()||
               udig.find(row+col) != udig.end()) continue;
            cols.insert(col);
            ddig.insert(row-col);
            udig.insert(row+col);
            recurse(row+1, n);
            cols.erase(col);
            ddig.erase(row-col);
            udig.erase(row+col);
        }
    }
};