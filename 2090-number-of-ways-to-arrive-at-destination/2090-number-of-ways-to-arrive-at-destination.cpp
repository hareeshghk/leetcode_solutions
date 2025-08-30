#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1000000007;
        auto graph = vector<vector<pair<int,int>>>(n, vector<pair<int,int>>());

        for (const auto& road : roads) {
            graph[road[0]].push_back(pair<int,int>(road[1], road[2]));
            graph[road[1]].push_back(pair<int,int>(road[0], road[2]));
        }

        vector<int> pathCount = vector<int>(n, 0);
        vector<long long> distance = vector<long long>(n, LLONG_MAX);

        auto pq = priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>();

        pq.push(pair<long long, int>(0, 0));
        pathCount[0] = 1;
        distance[0] = 0;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            long long currentDistance = top.first;
            int node = top.second;

            if (currentDistance > distance[node]) continue;

            for (const auto& nei : graph[node]) {
                if (currentDistance + nei.second < distance[nei.first]) {
                    distance[nei.first] = currentDistance + nei.second;
                    pathCount[nei.first] = pathCount[node];
                    pq.push(pair<long long, int>(currentDistance + nei.second, nei.first));
                } else if (currentDistance + nei.second == distance[nei.first]) {
                    pathCount[nei.first] = (pathCount[nei.first] + pathCount[node])%mod;
                }
            }
        }
        return pathCount[n-1];
    }
};
