class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        
        for (auto task:tasks) {
            freq[task-'A']++;
        }
        
        priority_queue<int> pq;
        
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) pq.push(freq[i]);
        }
        
        //queue
        queue<pair<int,int>> q;
        int time = 0;
        
        while(!pq.empty() || !q.empty()) {
            time+=1;
            
            if (!pq.empty()) {
                auto cur = pq.top();
                pq.pop();
                cur--;
                if (cur != 0) {
                    q.push(pair(cur, time + n));
                }
            }
            
            if (!q.empty()) {
                if (q.front().second == time) {
                    pq.push(q.front().first);
                    q.pop();
                }
            }
            
            if (pq.empty() && !q.empty()) {
                time = (q.front().second) - 1;
            }
        }
        return time;
    }
};