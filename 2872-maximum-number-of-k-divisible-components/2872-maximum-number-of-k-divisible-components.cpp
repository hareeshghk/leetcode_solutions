class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> graph = vector<vector<int>>(n);

        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        // pick root at random
        int root = n/2;

        // updates values with cummulative sum on subtree.
        dfs(root, graph, values, -1, k);
        int ans = 0;
        for (auto val : values) {
            if (val %k == 0) ans++;
        }

        return ans;
    }
private:
    int dfs(int root, vector<vector<int>> &g, vector<int> &v, int parent, int k) {
        int currentSum = v[root];
        for (auto child : g[root]) {
            if (child == parent) {
                continue;
            }
            currentSum = (currentSum + dfs(child, g, v, root, k))%k;
        }

        v[root] = currentSum;
        return currentSum;
    }
};