#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> mapper;
        int counter = 0;
        
        for (auto eq : equations) {
            if(mapper.find(eq[0]) == mapper.end()) mapper[eq[0]]=counter++;
            if(mapper.find(eq[1]) == mapper.end()) mapper[eq[1]]=counter++;
        }
        
        vector<vector<pair<int,double>>> graph(counter, vector<pair<int,double>>());
        
        for (int i = 0; i <  equations.size(); ++i) {
            graph[mapper[equations[i][0]]].push_back(pair<int,double>(mapper[equations[i][1]], values[i]));
            graph[mapper[equations[i][1]]].push_back(pair<int,double>(mapper[equations[i][0]], 1.0/values[i]));
        }
        
        vector<vector<double>> distances(counter, vector<double>(2, -1));
        
        for (int i = 0; i < counter; ++i) {
            // not visited
            if (distances[i][0] == -1) {
                int parent = i;
                distances[i][0] = 1;
                distances[i][1] = i;
                dfs(i, distances, graph, parent);
            }
        }
        
        int q = queries.size();
        vector<double> result(q);
        
        string num, den;
        int num_idx, den_idx;
        for (int i = 0; i < q; ++i) {
            num = queries[i][0];
            den = queries[i][1];
            
            if (mapper.find(num) == mapper.end() ||
               mapper.find(den) == mapper.end()) {
                result[i] = -1;
                continue;
            }
            num_idx = mapper[num];
            den_idx = mapper[den];
            
            int num_parent = distances[num_idx][1];
            int den_parent = distances[den_idx][1];
            
            if (num_parent != den_parent) {
                result[i] = -1;
                continue;
            }
            
            result[i] = distances[den_idx][0]/distances[num_idx][0];
        }
        return result;
    }
    
    void dfs(int root, vector<vector<double>> &distances, vector<vector<pair<int,double>>> &graph, int parent) {
        for (auto child : graph[root]) {
            if (distances[child.first][0] != -1) continue;
            distances[child.first][0] = distances[root][0]*child.second;
            distances[child.first][1] = parent;
            dfs(child.first, distances, graph, parent);
        }
    }
};
