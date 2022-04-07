class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap;
        for (auto stone : stones) {
            maxheap.push(stone);
        }
        
        int s1,s2;
        while (maxheap.size() > 1) {
            s1 = maxheap.top();
            maxheap.pop();
            s2 = maxheap.top();
            maxheap.pop();
            if (s1!=s2) {
                maxheap.push(s1-s2);
            }
        }
        
        if (maxheap.empty()) return 0;
        return maxheap.top();
    }
};