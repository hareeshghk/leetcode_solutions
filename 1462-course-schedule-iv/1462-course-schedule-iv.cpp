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
        vector<unordered_set<int>> prereq(numCourses, unordered_set<int>());
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
                prereq[nei].insert(cur);
                prereq[nei] = mergeSets(prereq[nei], prereq[cur]);
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
            
            if (prereq[q[1]].count(q[0]) == 0) {
                result.push_back(false);
                continue;
            }
            result.push_back(true);
        }
        
        return result;
    }
    
    unordered_set<int> mergeSets(unordered_set<int> &a, unordered_set<int> &b) {
        for (auto val : b) {
            a.insert(val);
        }
        return a;
    }
};