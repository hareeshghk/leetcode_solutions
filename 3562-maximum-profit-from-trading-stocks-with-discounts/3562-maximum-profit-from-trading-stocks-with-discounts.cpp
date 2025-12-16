class Solution {
    vector<vector<int>> tree;
    vector<int> bp, sp;
    int budget;
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        this->budget = budget;
        bp = present;
        sp = future;

        tree = vector<vector<int>>(n, vector<int>());

        for (auto& hi : hierarchy) {
            tree[hi[0]-1].push_back(hi[1]-1);
        }

        auto ans = dfs(0);

        return ans[budget][0];
    }
private:
    vector<vector<int>> dfs(int root) {
        vector<vector<int>> dp = vector<vector<int>>(budget+1, vector<int>(2, 0));

        for (auto child : tree[root]) {
            auto current = dfs(child);
            vector<vector<int>> combined = vector<vector<int>>(budget+1, vector<int>(2, 0));
            for (int bud = 0; bud <= budget; ++bud) {
                for (int x = 0; x <= bud; ++x) {
                    combined[bud][0] = max(combined[bud][0], current[x][0] + dp[bud-x][0]);
                    combined[bud][1] = max(combined[bud][1], current[x][1] + dp[bud-x][1]);
                }
            }
            dp = combined;
        }

        vector<vector<int>> ans = vector<vector<int>>(budget+1, vector<int>(2, 0));

        for (int bud = 0; bud <= budget; ++bud) {
            // roots parent didn't buy.
            ans[bud][0] = dp[bud][0];
            if (bud >= bp[root]) {
                ans[bud][0] = max(ans[bud][0], sp[root]-bp[root] + dp[bud-bp[root]][1]);
            }

            // roots parent bought.
            int discount = bp[root]/2;
            ans[bud][1] = dp[bud][0];
            if (bud >= discount) {
                ans[bud][1] = max(ans[bud][1], sp[root]-discount + dp[bud-discount][1]);
            }
        }
        return ans;
    }
};