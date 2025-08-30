#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
    struct comparator {
        bool operator()(pair<int,int> &p1, pair<int,int> &p2) {
            return p1.second > p2.second;
        }
    };
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1, vector<pair<int,int>>());
        
        // creating graph O(E)
        for (auto time : times) {
            graph[time[0]].push_back(make_pair(time[1], time[2]));
        }
        
        // dijikistra priority queue with weights.
        priority_queue<pair<int,int>, vector<pair<int,int>>, comparator> minheap;
        
        minheap.push(make_pair(k, 0));
        
        vector<int> timetaken(n+1, -1);
        int maxtimetaken = 0, visitedcount = 0;
        while (!minheap.empty()) {
            auto cur = minheap.top();
            minheap.pop();
            
            if (timetaken[cur.first] != -1) continue;
            
            timetaken[cur.first] = cur.second;
            ++visitedcount;
            maxtimetaken = cur.second;
            
            for (auto edge : graph[cur.first]) {
                if (timetaken[edge.first] == -1) {
                    minheap.push(make_pair(edge.first, edge.second+cur.second));
                }
            }
        }
        if (visitedcount != n) return -1;
        return maxtimetaken;
    }
};
