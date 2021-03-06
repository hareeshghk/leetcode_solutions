class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> visited(n, false);
        
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        int result = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                result++;
                dfs(i, graph, visited);
            }
        }
        return result;
    }
    
    void dfs(int v, vector<vector<int>> &graph, vector<bool> &vis) {
        vis[v] = true;
        
        for (auto nei : graph[v]) {
            if (!vis[nei]) {
                dfs(nei, graph, vis);
            }
        }
    }
};