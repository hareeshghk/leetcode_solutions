#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        struct minpair {
          bool operator()(const vector<int> &a, const vector<int> &b) {
              return a[0]+a[1] > b[0]+b[1];
          }  
        };
        
        priority_queue<vector<int>, vector<vector<int>>, minpair> minheap;
        
        // minheap.push({nums1[0]+nums2[0],0,0});
        
        int m = nums1.size();
        int n = nums2.size();
        
        for (int i = 0; i < m; ++i) {
            minheap.push({nums1[i], nums2[0], 0});
        }
        
        vector<vector<int>> result;
        while (!minheap.empty()) {
            auto cur = minheap.top();
            minheap.pop();
            
            result.push_back({cur[0], cur[1]});
            k--;
            if(k==0) break;
            
            
            if (cur[2] == n-1) continue;
            
            minheap.push({cur[0], nums2[cur[2]+1], cur[2]+1});
        }
        return result;
    }
};
