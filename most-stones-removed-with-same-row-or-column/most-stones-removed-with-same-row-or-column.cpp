#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> rows, columns;
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        set<pair<int,int>> visited;
        
        for (int i = 0; i < n; ++i) {
            rows[stones[i][0]].push_back(i);
            columns[stones[i][1]].push_back(i);
        }
        
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (visited.count(pair<int,int>(stones[i][0],stones[i][1])) == 0) {
                ++result;
                dfs(stones[i][0],stones[i][1], visited, stones);
            }
        }
        return n-result;
    }
    
    void dfs(int row, int col, set<pair<int,int>> &vis, vector<vector<int>> &stones) {
        vis.insert(pair<int,int>(row, col));
        for (auto s : rows[row]) {
            int newr, newc;
            newr = stones[s][0];
            newc = stones[s][1];
            
            if (vis.count(pair<int,int>(newr, newc)) == 0) {
                dfs(newr, newc, vis, stones);
            }
        }
        
        for (auto s : columns[col]) {
            int newr, newc;
            newr = stones[s][0];
            newc = stones[s][1];
            
            if (vis.count(pair<int,int>(newr, newc)) == 0) {
                dfs(newr, newc, vis, stones);
            }
        }
    }
};
