#include <algorithm>
#include <vector>

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        // create adjacency matrix
        vector<vector<int>> graph(n, vector<int>(n, INT_MAX));
        for (auto edge : edges) {
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        }
        
        // apply floyd warshall
        floydWarshall(graph);
        
        int min_number_of_cities=INT_MAX, result=-1;
        for (int i = 0;i<n;i++) {
            int num_cities = 0;
            for (int j = 0; j < n; j++) {
                if (i==j) continue;
                if (graph[i][j] <= distanceThreshold) num_cities++;
            }
            if (num_cities <= min_number_of_cities) {
                min_number_of_cities = num_cities;
                result = i;
            }
        }
        return result;
    }
    
    void floydWarshall(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<vector<int>> temp = graph;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (graph[j][i] != INT_MAX && graph[i][k] != INT_MAX) {
                        temp[j][k] = min(graph[j][k], graph[j][i]+graph[i][k]);
                    }
                }
            }
            graph = temp;
        }
    }
};
