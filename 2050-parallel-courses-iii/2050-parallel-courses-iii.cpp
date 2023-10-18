class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // start with nodes with 0 inrate
        // every time choose nodes with 0 inrate and update neighbours with time.
        
        vector<vector<int>> graph = vector<vector<int>>(n, vector<int>());
        vector<int> inrate = vector<int>(n, 0);
        for (auto relation : relations) {
            graph[relation[0]-1].push_back(relation[1]-1);
            inrate[relation[1]-1]++;
        }
        
        int minTimetoComplete = 0;
        vector<int> actualTimeTaken = vector<int>(n, 0);
        for (int i = 0; i < n; ++i) {
            actualTimeTaken[i] = time[i];
            minTimetoComplete = max(minTimetoComplete, time[i]);
        }
        // find nodes with inrate 0.
        queue<int> zeroInrateNodes = queue<int>();
        for (int i = 0; i < n; ++i) {
            if (inrate[i] == 0) {
                zeroInrateNodes.push(i);
            }
        }
        
        // topological iteration
        while (!zeroInrateNodes.empty()) {
            int top = zeroInrateNodes.front();
            zeroInrateNodes.pop();
            
            for (auto neighbour : graph[top]) {
                actualTimeTaken[neighbour] = max(actualTimeTaken[neighbour], actualTimeTaken[top]+time[neighbour]);
                minTimetoComplete = max(minTimetoComplete, actualTimeTaken[neighbour]);
                inrate[neighbour]--;
                if (inrate[neighbour] == 0) {
                   zeroInrateNodes.push(neighbour); 
                }
            }
        }
        return minTimetoComplete;
    }
};