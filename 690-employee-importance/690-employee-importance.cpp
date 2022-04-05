/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> rev_id_map;
        for (auto e : employees) {
            rev_id_map[e->id] = e;
        }
        return dfs(id, rev_id_map);
    }
    
    int dfs(int id, unordered_map<int, Employee*> &rev_id_map) {
        auto e = rev_id_map[id];
        int result = 0;
        result += e->importance;
        
        for (auto subordinate : e->subordinates) {
            result += dfs(subordinate, rev_id_map);
        }
        return result;
    }
};