#include <algorithm>
#include <map>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // result.
        vector<int> result;
        if (tasks.size() == 0) return result;
        
        map<int,vector<int>> taskstoindexmap;
        
        for (int i = 0; i < tasks.size(); ++i) {
            if (taskstoindexmap.find(tasks[i][0]) == taskstoindexmap.end()) taskstoindexmap[tasks[i][0]] = {};
            taskstoindexmap[tasks[i][0]].push_back(i);
        }
        
        
        typedef pair<int,int> cell;
        struct mycomp {
            bool operator()(cell a, cell b) {
                return (a.first > b.first) || (a.first == b.first && a.second > b.second);
            }
        };
        
        // to choose which one to take
        priority_queue<cell, vector<cell>, mycomp> pq;
        
        // tasks map iterator
        auto taskitr = taskstoindexmap.begin();
        
        // start time as 0.
        long long int time = taskitr->first;
        
        // filling first task
        for (auto k : taskitr->second) {
            pq.push(cell(tasks[k][1], k));
        }
        taskitr++;
        
        while (!pq.empty() || taskitr != taskstoindexmap.end()) {
            while (taskitr !=  taskstoindexmap.end()) {
                if (taskitr->first <= time) {
                    for (auto k : taskitr->second) {
                        pq.push(cell(tasks[k][1], k));
                    }
                    taskitr++;
                } else break;
            }
            
            if (pq.empty()) {
                if (taskitr == taskstoindexmap.end()) break;
                time = taskitr->first;
                continue;
            }
            
            auto cur = pq.top();
            pq.pop();
            result.push_back(cur.second);
            time += (long long int)cur.first;
        }
        return result;
    }
};
