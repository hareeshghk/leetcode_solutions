class TaskManager {
    unordered_map<int, int> taskPriorityMap;
    unordered_map<int, int> taskUserIDMap;
    map<int, set<int>> priorityTaskSetMap;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto task : tasks) {
            taskPriorityMap[task[1]] = task[2];
            taskUserIDMap[task[1]] = task[0];
            priorityTaskSetMap[task[2]].insert(task[1]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        taskPriorityMap[taskId] = priority;
        taskUserIDMap[taskId] = userId;
        priorityTaskSetMap[priority].insert(taskId);
    }
    
    void edit(int taskId, int newPriority) {
        int currentPriority = taskPriorityMap[taskId];
        priorityTaskSetMap[currentPriority].erase(taskId);

        if (priorityTaskSetMap[currentPriority].size() == 0) {
            priorityTaskSetMap.erase(currentPriority);
        }

        taskPriorityMap[taskId] = newPriority;
        priorityTaskSetMap[newPriority].insert(taskId);
    }
    
    void rmv(int taskId) {
        int currentPriority = taskPriorityMap[taskId];
        priorityTaskSetMap[currentPriority].erase(taskId);
        if (priorityTaskSetMap[currentPriority].size() == 0) {
            priorityTaskSetMap.erase(currentPriority);
        }
        taskPriorityMap.erase(taskId);
        taskUserIDMap.erase(taskId);
    }
    
    int execTop() {
        if (priorityTaskSetMap.size() == 0) {
            return -1;
        }
        int taskId = *(priorityTaskSetMap.rbegin()->second.rbegin());
        int userId = taskUserIDMap[taskId];
        rmv(taskId); 
        return userId;      
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */

 /*
 taskid, priority -> map
 taskid <-> userid

 priority -> taskid set
 */