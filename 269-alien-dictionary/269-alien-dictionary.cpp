#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> inorder;
        
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].length(); ++j) {
                inorder[words[i][j]] = 0;
                graph[words[i][j]] = vector<char>();
            }
        }
        
        for (int i = 1; i < words.size(); ++i) {
            int j;
            int minlength = min(words[i].length(), words[i-1].length());
            for (j = 0; j < minlength; ++j) {
                if (words[i][j] != words[i-1][j]) break;
            }
            
            if (j != minlength) {
                graph[words[i-1][j]].push_back(words[i][j]);
                inorder[words[i][j]]++;
            } else {
                if (words[i-1].length() > words[i].length()) return "";
            }
        }
        
        
        queue<char> sources;
        for (auto order : inorder) {
            if (order.second == 0) sources.push(order.first);
        }
        
        string result = "";
        
        while (!sources.empty()) {
            auto curvertex = sources.front();
            sources.pop();
            result += curvertex;
            
            for (auto neighbor : graph[curvertex]) {
                inorder[neighbor]--;
                if (inorder[neighbor] == 0) {
                    sources.push(neighbor);
                }
            }
        }
        
        if (result.length() != inorder.size()) return "";
        return result;
    }
};
