class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int num_nodes = graph.size();
        
        if (num_nodes == 1) return 0;
        
        // we can use mask because max num_nodes is 12.
        vector<vector<bool>> visited(num_nodes, vector<bool>(1 << num_nodes, false));
        
        int endmask = (1<<num_nodes) - 1;
        
        typedef pair<int, int> cell;
        // bfs queue with node and its mask.
        queue<cell> qu;
        
        for (int i = 0; i < num_nodes; ++i) {
            qu.push(cell(i, 1<<i));
            visited[i][1<<i] = true;
        }
        
        int steps = 0;
        while (!qu.empty()) {
            int cursize = qu.size();
            for (int i = 0; i < cursize; ++i) {
                auto curfront = qu.front();
                qu.pop();
                for (auto neighbour : graph[curfront.first]) {
                    int newmask = curfront.second | (1<<neighbour);
                    if (newmask == endmask) return steps + 1;
                    if (!visited[neighbour][newmask]) {
                        visited[neighbour][newmask] = true;
                        qu.push(cell(neighbour, newmask));
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};