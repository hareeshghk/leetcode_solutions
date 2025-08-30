#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class DSU {
    vector<int> parents;
    vector<int> rank;
    int n;
public:
    DSU(int n) {
        this->n = n;
        parents.resize(n);
        rank.resize(n, 1);
        
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
        }
    }
    
    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    
    bool unionize(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        
        if (pa==pb) return false;
        
        if (rank[pa]>=rank[pb]) {
            parents[pb] = pa;
            rank[pa] += rank[pb];
        } else {
            parents[pa] = pb;
            rank[pb] += rank[pa];
        }
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // using kruskal
        int n = points.size();
        DSU d(n);
        
        vector<vector<int>> edges;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                int dist = getManhanttanDistance(points[i], points[j]);
                
                edges.push_back({i,j,dist});
            }
        }
        
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b){return a[2] < b[2];});
        
        int result = 0;
        int count = n-1;
        for (auto edge : edges) {
            if (d.unionize(edge[0], edge[1])) {
                result += edge[2];
                --count;
                if (count == 0) break;
            }
        }
        return result;
    }
    
    int getManhanttanDistance(vector<int> &a, vector<int> &b) {
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
};
