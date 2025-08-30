#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        int maxelem =INT_MIN;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> minheap;
        
        for (int i = 0; i < n; i++) {
            minheap.push(make_pair(nums[i][0], make_pair(0, i))); // num, index in a row, row num
            maxelem = max(maxelem, nums[i][0]);
        }
        
        int range = INT_MAX;
        int start, end;
        
        while (!minheap.empty() && minheap.size() == n) {
            auto cur = minheap.top();
            minheap.pop();
            if (range > maxelem - cur.first) {
                range = maxelem - cur.first;
                start = cur.first;
                end = maxelem;
            }
            if (nums[cur.second.second].size() != cur.second.first+1) {
                cur.second.first++;
                cur.first = nums[cur.second.second][cur.second.first];
                maxelem = max(maxelem, cur.first);
                minheap.push(cur);
            }
        }
        return {start, end};
    }
};
