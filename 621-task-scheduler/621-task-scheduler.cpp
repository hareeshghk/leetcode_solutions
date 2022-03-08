class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (auto task : tasks) {
            freq[task-'A']++;
        }
        
        sort(freq.begin(), freq.end());
        
        int maxslotsidle = (freq[25]-1)*n;
        for (int i = 24; i >=0; i--) {
            maxslotsidle -= min(freq[25]-1, freq[i]);
        }
        
        maxslotsidle = max(0, maxslotsidle);
        
        
        return maxslotsidle+tasks.size();
    }
};