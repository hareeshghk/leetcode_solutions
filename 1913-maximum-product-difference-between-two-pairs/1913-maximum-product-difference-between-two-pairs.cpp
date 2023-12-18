class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        auto minheap = priority_queue<int, vector<int>, greater<int>>();
        auto maxheap = priority_queue<int>();
        
        for (auto num : nums) {
            if (minheap.size() < 2) {
                minheap.push(num);
            } else if (num > minheap.top()) {
                minheap.pop();
                minheap.push(num);
            }
            
            if (maxheap.size() < 2) {
                maxheap.push(num);
            } else if (num < maxheap.top()) {
                maxheap.pop();
                maxheap.push(num);
            }
        }
        
        int a,b,c,d;
        a = minheap.top();minheap.pop();
        b = minheap.top();minheap.pop();
        
        c = maxheap.top();maxheap.pop();
        d = maxheap.top();maxheap.pop();
        
        return (a*b) - (c*d);
    }
};