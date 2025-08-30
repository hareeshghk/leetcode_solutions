#include <algorithm>
#include <vector>

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size();
        int m = edges2.size();

        auto targets1 = getTargets(edges1, k);
        auto targets2 = getTargets(edges2, k-1);


        int maxVal = 0;
        for (auto val : targets2) {
            maxVal = max(maxVal, val);
        }

        for (int i = 0; i < targets1.size(); ++i) {
            targets1[i] += maxVal;
        }

        return targets1;
    }
private:
    int dfs(int node, int parent, vector<vector<int>> &graph, int k) {
        if (k < 0) {
            return 0;
        }

        int result = 1;

        for (auto nei : graph[node]) {
            if (nei == parent) continue;
            result += dfs(nei, node, graph, k-1);
        }
        return result;
    }
    
    vector<int> getTargets(vector<vector<int>> &edges, int k) {
        int n = edges.size() + 1;

        vector<vector<int>> graph = vector<vector<int>>(n, vector<int>());
        vector<int> targets = vector<int>(n, 0);

        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; ++i) {
            targets[i] = dfs(i, -1, graph, k);
        }
        return targets;
    }
};
