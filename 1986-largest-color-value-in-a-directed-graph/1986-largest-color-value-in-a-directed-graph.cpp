class Solution {
public:
    int largestPathValue(string colours, vector<vector<int>>& edges) {
        int n = colours.size();

        vector<vector<int>> count = vector<vector<int>>(n, vector<int>(27, 0));
        vector<int> indegree = vector<int>(n, 0);

        vector<vector<int>> graph = vector<vector<int>>(n);

        for (auto &edge : edges) {
            indegree[edge[1]]++;
            graph[edge[0]].push_back(edge[1]);
        }

        queue<int> nodes;

        for (int i= 0; i < n; ++i) {
            if (indegree[i] == 0) {
                count[i][colours[i]-'a'] = 1;
                count[i][26] = 1;
                nodes.push(i);
            }
        }

        int answer = 0;
        int nodesCovered = 0;
        while (!nodes.empty()) {
            int node = nodes.front();
            nodesCovered++;
            answer = max(answer, count[node][26]);
            nodes.pop();

            for (auto nei : graph[node]) {
                indegree[nei]--;
                int maxVal = 0;
                for (int i = 0; i < 26; ++i) {
                    count[nei][i] = max(count[nei][i], count[node][i]);
                    maxVal = max(maxVal, count[nei][i]);
                }
                count[nei][26] = maxVal;

                if (indegree[nei] == 0) {
                    count[nei][colours[nei]-'a']++;

                    if (count[nei][colours[nei]-'a'] > count[nei][26]) {
                        count[nei][26] = count[nei][colours[nei]-'a'];
                    }

                    nodes.push(nei);
                }
            }
        }

        // if cycle exists.
        if (nodesCovered < n) {
            return -1;
        }

        return answer;
    }
};