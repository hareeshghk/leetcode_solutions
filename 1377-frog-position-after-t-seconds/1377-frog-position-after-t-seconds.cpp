#include <iostream>
#include <list>
#include <queue>
#include <vector>

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        // creating adjaceny list for graph.
        vector<vector<int>> graph(n+1, vector<int>{});
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        typedef struct cell {
            int first;
            double second;
            int parent;
        } cell;
        graph[1].push_back(1);
        queue<cell> qu;
        qu.push(cell{1, 1.0, 1});
        
        for (int j = 0; j < t && !qu.empty(); j++) {
            int cursize = qu.size();
            for (int i = 0; i < cursize; i++) {
                cell curtop = qu.front();
                qu.pop();
                
                if (graph[curtop.first].size() == 1) {
                    qu.push(curtop);
                    continue;
                }
                
                for (auto neighbour : graph[curtop.first]) {
                    if (neighbour != curtop.parent) {
                        qu.push(cell{neighbour, curtop.second *(1.0/(graph[curtop.first].size()-1)), curtop.first});
                    }
                }
            }
        }
        
        // after level look at queue for answer.
        while (!qu.empty()) {
            cell curtop = qu.front();
            qu.pop();
            if (curtop.first == target) return curtop.second;
        }
        return 0;
    }
};
