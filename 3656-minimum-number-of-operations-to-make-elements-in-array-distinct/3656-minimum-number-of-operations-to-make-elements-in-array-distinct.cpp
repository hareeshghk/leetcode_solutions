#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> lastOccurrence;

        int n = nums.size();
        int index;
        for (index = n-1; index >= 0; --index) {
            if (lastOccurrence.find(nums[index]) == lastOccurrence.end()) {
                lastOccurrence.insert(nums[index]);
            } else {
                break;
            }
        }

        return (index + 3)/3;
    }
};
