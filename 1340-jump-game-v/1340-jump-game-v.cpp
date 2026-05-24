class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        // n*d for directed graoh
        int n = arr.size();
        vector<vector<int>> graph = vector<vector<int>>(n, vector<int>());
        vector<int> inorder = vector<int>(n, 0);
        vector<int> maxreachcount = vector<int>(n, 1);
        int answer = 1;

        for (int i = 0; i < n; ++i) {
            // to left
            for (int j = 1; j <= d && i-j >= 0; ++j) {
                if (arr[i-j] >= arr[i]) break;
                graph[i].push_back(i-j);
                inorder[i-j]++;
            }

            // to right
            for (int j = 1; j <= d && i+j < n; ++j) {
                if (arr[i+j] >= arr[i]) break;
                graph[i].push_back(i+j);
                inorder[i+j]++;
            }
        }

        // for (int i = 0; i < n; ++i) {
        //     cout << i << " -> ";
        //     for (auto nei : graph[i]) {
        //         cout << nei << ", ";
        //     }
        //     cout << endl;
        // }

        // inorder 0 push to a queue and maintain a vector for max count
        // topological graph traversal and get max count
        queue<int> qu;

        for (int i = 0; i < n; ++i) {
            if (inorder[i] == 0) qu.push(i);
        }

        while (!qu.empty()) {
            int root = qu.front();
            qu.pop();

            answer = max(answer, maxreachcount[root]);

            for (auto nei : graph[root]) {
                inorder[nei]--;
                maxreachcount[nei] = max(maxreachcount[nei], maxreachcount[root]+1);

                if (inorder[nei] == 0) qu.push(nei);
            }
        }

        return answer;
    }
};