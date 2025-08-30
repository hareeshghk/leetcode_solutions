#include <cmath>
#include <string>
#include <unordered_set>

class Solution {
public:
    int total_combinations;
    string crackSafe(int n, int k) {
        total_combinations = pow(k, n);
        
        string start (n, '0');
        
        string result = start;
        
        unordered_set<string> visited;
        
        visited.insert(start);
        
        bool found = backtrack(start, visited, result, k);
        
        return result;
    }
    
    bool backtrack(string &start, unordered_set<string> &visited, string &result, int k) {
        if (visited.size() == total_combinations) {
            return true;
        }
        
        string nextPrefix = start.substr(1);
        
        string next;
        for (int i = 0; i < k; ++i) {
            char ch = '0'+i;
            next = nextPrefix + ch;
            if (visited.count(next) == 0) {
                visited.insert(next);
                result += ch;
                if(backtrack(next, visited, result, k)) return true;
                result.pop_back();
                visited.erase(next);
            }
        }
        return false;
    }
};
