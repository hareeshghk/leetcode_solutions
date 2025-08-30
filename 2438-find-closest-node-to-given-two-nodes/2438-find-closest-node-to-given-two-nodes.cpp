#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // 2 dfs's
        int n = edges.size();
        vector<int> distances1 = getDistances(edges, node1);
        vector<int> distances2 = getDistances(edges, node2);

        int minValue = INT_MAX, minIndex = -1;
        for (int i = 0; i < n; ++i) {
            if (distances1[i] != -1 && distances2[i] != -1) {
                int distance = max(distances1[i], distances2[i]);
                if (distance < minValue) {
                    minValue = distance;
                    minIndex = i;
                } else if (distance == minValue) {
                    if (i < minIndex) {
                        minIndex = i;
                    }
                }
            }
        }
        return minIndex;
    }
private:
    vector<int> getDistances(vector<int> &edges, int root) {
        int n = edges.size();
        vector<int> distances = vector<int>(n, -1);
        distances[root] = 0;
        dfs(edges, root, distances);
        return distances;
    }

    void dfs(vector<int> &edges, int root, vector<int> &distances) {
        if (edges[root] != -1 && distances[edges[root]] == -1) {
            distances[edges[root]] = distances[root] + 1;
            dfs(edges, edges[root], distances);
        }
    }
};
