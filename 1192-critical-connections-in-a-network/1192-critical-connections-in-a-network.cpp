#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n, vector<int>());
        
        for (auto c : connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        
        vector<int> time(n,-1), low(n,-1),parent(n,-1);
        for (int i = 0; i < n; i++) {
            if(time[i] == -1) {
                dfs(i, graph, time, low, parent);
            }
        }
        return result;
    }
    
    void dfs(int u, vector<vector<int>> &g, vector<int> &time, vector<int> &low, vector<int> &parent) {
        static int t = 0;
        time[u] = t;
        low[u] = t;
        ++t;
        int children = 0;
        for (auto nei : g[u]) {
            if(time[nei] == -1) {
                ++children;
                parent[nei] = u;
                dfs(nei,g,time,low,parent);
                low[u] = min(low[u], low[nei]);
                if (low[nei] > time[u]) {
                    result.push_back({u,nei});
                }
            } else if(parent[u] != nei) {
                low[u] = min(low[u], time[nei]);
            }
        }
    }
};
