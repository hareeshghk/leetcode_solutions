#include <vector>

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n, -1);
        // colour nodes with 0 or 1;
        for (int  i = 0; i < n; i++) {
            if (colour[i] == -1) {
                if (!dfs(i, graph, colour, 0)) return false;
            }
        }
        return true;
    }
    
    bool dfs(int root, vector<vector<int>>& graph, vector<int> &colour, int current_colour) {
        if (colour[root] != -1) {
            if (colour[root] == current_colour) return true;
            return false;
        }
        
        colour[root] = current_colour;
        for (auto neighbour : graph[root]) {
            if (!dfs(neighbour, graph, colour, 1-current_colour)) return false;
        }
        return true;
    }
};
