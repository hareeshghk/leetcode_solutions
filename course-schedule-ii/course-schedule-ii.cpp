class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // adjacency graph
        vector<vector<int>> graph(numCourses, vector<int>{});
        // vector to store result order.
        vector<int> result;
        // vector to store indegree of each node.
        vector<int> inDegree(numCourses, 0);
        
        for (auto prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            inDegree[prerequisite[0]]++;
        }
        
        queue<int> sources;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) {
                sources.push(i);
            }
        }
        
        while (!sources.empty()) {
            auto val = sources.front();
            sources.pop();
            
            // add it to result as there are no prereq left for val.
            result.push_back(val);
            
            for (auto neighbour : graph[val]) {
                inDegree[neighbour]--;
                if (inDegree[neighbour] == 0) {
                    sources.push(neighbour);
                }
            }
        }
        
        if (result.size() != numCourses) {
            return vector<int>{};
        }
        
        return result;
    }
};