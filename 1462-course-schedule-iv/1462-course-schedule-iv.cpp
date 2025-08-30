#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> inOrder(numCourses, 0);
        
        vector<vector<int>> graph(numCourses, vector<int> ());
        
        for (auto p : prerequisites) {
            graph[p[0]].push_back(p[1]);
            inOrder[p[1]]++;
        }
        
        queue<int> q;
        vector<vector<bool>> dp(numCourses, vector<bool>(numCourses, false));
        
        // if inorder is 0 push to queue;
        for (int i = 0; i < numCourses; ++i) {
            if (inOrder[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            for (auto nei : graph[cur]) {
                inOrder[nei]--;
                dp[cur][nei] = true;
                
                for (int i = 0; i < numCourses; ++i) {
                    dp[i][nei] = (dp[i][nei] || dp[i][cur]);
                }
                if (inOrder[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        
        vector<bool> result;
        
        for (auto q : queries) {
            if (q[1] >= numCourses || q[1] < 0) {
                result.push_back(false);
                continue;
            }
            
            if (q[0] >= numCourses || q[0] < 0) {
                result.push_back(false);
                continue;
            }
            
            result.push_back(dp[q[0]][q[1]]);
        }
        
        return result;
    }
};
