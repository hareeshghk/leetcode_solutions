#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> evens;
        int minval = INT_MAX; // make sure nums have atleast one num
        for (auto num : nums) {
            if (num&1) {
                evens.push(num*2);
                minval = min(minval, num*2);
            } else {
                evens.push(num);
                minval = min(minval, num);
            }
        }
        
        int mindeviation = INT_MAX;
        while (!evens.empty()) {
            auto cur = evens.top();
            evens.pop();
            mindeviation = min(mindeviation, cur - minval);
            if (cur%2 == 0) {
                evens.push(cur/2);
                minval = min(minval, cur/2);
            } else {
                break;
            }
        }
        return mindeviation;
    }
};
