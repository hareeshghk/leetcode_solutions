class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>{});
        vector<int> inOrder(numCourses, 0);
        
        for (auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            inOrder[p[0]]++;
        }
        
        queue<int> sources;
        
        for (int i = 0; i < numCourses; ++i) {
            if (inOrder[i]==0)
            sources.push(i);
        }
        
        int counter = 0;
        while (!sources.empty()) {
            auto root = sources.front();
            sources.pop();
            counter++;
            
            for (auto nei : graph[root]) {
                inOrder[nei]--;
                if (inOrder[nei] == 0) {
                    sources.push(nei);
                }
            }
        }
        
        return counter == numCourses;
    }
    
};