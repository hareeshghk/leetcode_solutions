#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    int numedges;
    bool found;
    vector<string> result;
    unordered_map<string, vector<bool>> visited;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        numedges = tickets.size();
        found = false;
        unordered_map<string, multiset<string>> graph;
        
        for (auto ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
            visited[ticket[0]].push_back(false);
        }
        
        vector<string> current_path {"JFK"};
        backtrack("JFK", graph, current_path, 0);
        return result;
    }
    
    void backtrack(string src, unordered_map<string, multiset<string>> &graph, vector<string> cur, int curedges) {
        if (curedges == numedges) {
            result = cur;
            found = true;
            return;
        }
        
        auto &neightbours = graph[src];
        int counter = 0;
        for (auto neighbour : neightbours) {
            if (visited[src][counter]) {
                ++counter;
                continue;
            }
            cur.push_back(neighbour);
            visited[src][counter] = true;
            backtrack(neighbour, graph, cur, curedges+1);
            if (found) return;
            visited[src][counter] = false;
            cur.pop_back();
            counter++;
        }
        return;
    }
};
