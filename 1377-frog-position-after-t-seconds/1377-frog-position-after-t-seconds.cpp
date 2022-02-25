class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        // creating adjaceny list for graph.
        vector<vector<int>> graph(n+1, vector<int>{});
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        //visited array.
        vector<bool> visited(n+1, false);
        
        typedef pair<int,double> cell;
        queue<cell> qu;
        qu.push(cell(1, 1.0));
        
        while(!qu.empty() && t--) {
            int cursize = qu.size();
            for (int i = 0; i < cursize; i++) {
                cell curtop = qu.front();
                qu.pop();
                // cout << curtop.first << " " <<curtop.second << endl;
                if (visited[curtop.first]) {
                    qu.push(curtop);
                    continue;
                }
                
                visited[curtop.first] = true;
                int valid_neighbours = 0;
                for (auto neighbour : graph[curtop.first]) {
                    if (!visited[neighbour]) {
                        valid_neighbours++;
                    }
                }
                
                if (valid_neighbours == 0) {
                    qu.push(curtop);
                    continue;
                }
                
                for (auto neighbour : graph[curtop.first]) {
                    if (!visited[neighbour]) {
                        qu.push(cell(neighbour, curtop.second * (1.0/valid_neighbours)));
                    }
                }
            }
        }
        
        while (!qu.empty()) {
            cell curtop = qu.front();
            qu.pop();
            if (curtop.first == target) return curtop.second;
        }
        return 0;
    }
};