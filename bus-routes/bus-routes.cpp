#include <algorithm>
#include <queue>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        unordered_map<int, vector<int>> edges;
        int n = routes.size();
        int counter = 0;
        for (auto route : routes) {
            for (auto stop : route) {
                edges[stop].push_back(counter);
            }
            ++counter;
        }
        
        // build graph betwee buses.
        vector<vector<int>> graph(n, vector<int>());
        for (auto edge : edges) {
            for (int i = 0; i < edge.second.size(); i++) {
                for (int j = i+1; j < edge.second.size(); ++j) {
                    graph[edge.second[i]].push_back(edge.second[j]);
                    graph[edge.second[j]].push_back(edge.second[i]);
                }
            }
        }
        
        // if src or target not present in graph
        if (edges.find(source) == edges.end()) return -1;
        if (edges.find(target) == edges.end()) return -1;
        
        // visited buses vector.
        vector<bool> visited(n, false);
        
        queue<int> srcBuses;
        set<int> dstBuses (edges[target].begin(), edges[target].end());
        for (int i = 0; i < edges[source].size(); ++i) {
            visited[edges[source][i]] = true;
            if (dstBuses.count(edges[source][i]) != 0) return 1;
            srcBuses.push(edges[source][i]);
        }
        
        int level = 1;
        while (!srcBuses.empty()) {
            int levelSize = srcBuses.size();
            for (int i = 0; i < levelSize; ++i) {
                auto cur = srcBuses.front();
                srcBuses.pop();
                
                if (dstBuses.count(cur) != 0) return level;
                
                for (auto neighbour : graph[cur]) {
                    if (visited[neighbour]) continue;
                    visited[neighbour] = true;
                    srcBuses.push(neighbour);
                }
            }
            ++level;
        }
        return -1;
    }
};
