class Node {
public:
    int nodeid;
    int pathsum;
    int charcount;
    Node(int _nodeid, int _pathsum, int _charcount) {
        nodeid = _nodeid;
        pathsum = _pathsum;
        charcount = _charcount;
    }

    bool operator<(const Node& other) const {
        return pathsum > other.pathsum;
    }
};

class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        // spread out from 0, along with weight

        vector<vector<pair<int,int>>> graph = vector<vector<pair<int, int>>>(n);

        for (auto edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<vector<int>> distance = vector<vector<int>>(n, vector<int>(k+1, INT_MAX));

        auto pq = priority_queue<Node>();

        pq.push(Node(0, 0, 1));
        distance[0][1] = 1;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            if (distance[top.nodeid][top.charcount] < top.pathsum) continue;

            if (top.nodeid == n-1) {
                return top.pathsum;
            }

            for (auto neighbour : graph[top.nodeid]) {
                int charcount = (labels[top.nodeid]==labels[neighbour.first])?(top.charcount+1):1;
                
                if (charcount > k) continue;

                int newpathsum = top.pathsum + neighbour.second;

                if (newpathsum < distance[neighbour.first][charcount]) {
                    distance[neighbour.first][charcount] = newpathsum;                    
                    pq.push(Node(neighbour.first, newpathsum, charcount));
                }
            }
        }

        return -1;
    }
};