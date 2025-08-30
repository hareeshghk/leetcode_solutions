#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nums;
    int result;
    int n;
    int countArrangement(int n) {
        nums.resize(n);
        this->n = n;
        for (int i = 0; i <n;i++) nums[i] = i+1;
        result = 0;
        travesepermutations(0);
        return result;
    }
    
    void travesepermutations(int idx) {
        if (idx == n) {
            ++result;
            return;
        }
        
        for (int i = idx; i <n ;i++) {
            if (nums[i]%(idx+1) == 0 || (idx+1)%nums[i]==0) {
                swap(nums[idx], nums[i]);
                travesepermutations(idx+1);
                swap(nums[idx], nums[i]);
            }
        }
        return;
    }
};
