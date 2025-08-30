#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size();
        int m = edges2.size();

        auto targets1 = getTargets(edges1, true);
        auto targets2 = getTargets(edges2, false);


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
    void dfs(int node, int parent, vector<vector<int>> &graph, vector<bool> &colours) {
        for (auto nei : graph[node]) {
            if (nei == parent) continue;

            colours[nei] = !colours[node];
            dfs(nei, node, graph, colours);
        }
        return;
    }
    
    vector<int> getTargets(vector<vector<int>> &edges, bool isEven) {
        int n = edges.size() + 1;

        vector<vector<int>> graph = vector<vector<int>>(n, vector<int>());
        vector<int> targets = vector<int>(n, 0);

        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> colours = vector<bool>(n, false);

        dfs(0, -1, graph, colours);
        
        int evens=0, odds=0;

        for (int i = 0; i < n; ++i) {
            if (colours[i]) {
                evens++;
            } else {
                odds++;
            }
        }

        for (int i = 0; i < n; ++i) {
            if (isEven) {
                targets[i] = colours[i]?evens:odds;
            } else {
                targets[i] = colours[i]?odds:evens;
            }
        }
        return targets;
    }
};
