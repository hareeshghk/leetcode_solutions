#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
public:
    struct freqcompare {
      bool operator()(pair<int, int> &p1, pair<int,int> &p2) {
          return p1.second > p2.second;
      }  
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        
        for (auto num : nums) {
            freq_map[num]++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, freqcompare> minheap;
        
        for (auto freq : freq_map) {
            if (minheap.size() < k) {
                minheap.push(freq);
            } else if (freq.second > minheap.top().second) {
                minheap.pop();
                minheap.push(freq);
            }
        }
        
        vector<int> result;
        
        while (!minheap.empty()) {
            result.push_back(minheap.top().first);
            minheap.pop();
        }
        return result;
    }
};
