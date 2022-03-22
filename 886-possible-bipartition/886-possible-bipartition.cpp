class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n, vector<int>());
        
        for (auto d : dislikes) {
            graph[d[0]-1].push_back(d[1]-1);
            graph[d[1]-1].push_back(d[0]-1);
        }
        vector<int> vis(n, -1);
        
        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                if (!dfs(i, 0, vis, graph)) return false;
            }
        }
        return true;
    }
    
    bool dfs(int root, int colour, vector<int>&vis, vector<vector<int>> &g) {
        if (vis[root] == -1) {
            vis[root] = colour;
        } else {
            if (vis[root] == colour) return true;
            return false;
        }
        
        colour = 1-colour;
        
        for (auto nei : g[root]) {
            if (!dfs(nei, colour, vis, g)) return false;
        }
        return true;
    }
};