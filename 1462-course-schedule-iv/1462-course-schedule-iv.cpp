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
                // prereq[nei] = mergeSets(prereq[nei], prereq[cur]);
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
            
            // unordered_set<int> visited;
            // result.push_back(dfs(q[1], q[0], prereq, visited));
            // if (prereq[q[1]].count(q[0]) == 0) {
            //     result.push_back(false);
            //     continue;
            // }
            result.push_back(dp[q[0]][q[1]]);
        }
        
        return result;
    }
    
    bool dfs(int src, int dst, vector<unordered_set<int>> &prereq, unordered_set<int> &vis) {
        if (src == dst) return true;
        vis.insert(src);
        
        unordered_set<int> src_set = prereq[src];
        bool result = false;
        for (auto val : prereq[src]) {
            if (vis.count(val) == 0) {
                src_set = mergeSets(src_set, prereq[val]);
                if (dfs(val, dst, prereq, vis)) {
                    result = true;
                }
            }
        }
        prereq[src] = src_set;
        return result;
    }
    
    unordered_set<int>& mergeSets(unordered_set<int> &a, unordered_set<int> &b) {
        for (auto val : b) {
            a.insert(val);
        }
        return a;
    }
};