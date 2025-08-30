#include <queue>
#include <vector>

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inOrder(numCourses, 0);
        vector<vector<int>> graph(numCourses, vector<int>());
        for (auto p : prerequisites) {
            inOrder[p[1]]++;
            graph[p[0]].push_back(p[1]);
        }
        
        queue<int> q;
        
        for (int i = 0; i < inOrder.size(); ++i) {
            if(inOrder[i] == 0) q.push(i);
        }
        
        int nodeCount = 0;
        while (!q.empty()) {
            auto curNode = q.front();
            q.pop();
            ++nodeCount;
            for (auto nei : graph[curNode]) {
                inOrder[nei]--;
                if (inOrder[nei] == 0)  q.push(nei);
            }
        }
        
        return (nodeCount == numCourses);
    }
};
