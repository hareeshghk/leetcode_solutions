#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> result;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int numedges = tickets.size();
        unordered_map<string, multiset<string>> graph;
        
        for (auto ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }
        
        DFS("JFK", graph);
        reverse(result.begin(), result.end());
        return result;
    }
    
    void DFS(string src, unordered_map<string, multiset<string>> &graph) {
        while (graph[src].size() != 0) {
            string next = *graph[src].begin();
            graph[src].erase(graph[src].begin());
            DFS(next, graph);
        }
        result.push_back(src);
    }
};
