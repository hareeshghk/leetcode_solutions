#include <vector>

class KthLargest {
    vector<int> vals;
    int k;
    int cursize;
public:
    struct comp {
        bool operator()(int a, int b) {
            return a > b;
        }
    };
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        vals = nums;
        cursize = nums.size();
        make_heap(vals.begin(), vals.end(), comp());
        while (vals.size() > k) {
            pop_heap(vals.begin(), vals.end(), comp());
            vals.pop_back();
            --cursize;
        }
    }
    
    int add(int val) {
        if (cursize < k) {
            vals.push_back(val);
            push_heap(vals.begin(), vals.end(), comp());
            ++cursize;
        }
        else if (val > vals[0]) {
            pop_heap(vals.begin(), vals.end(), comp());
            vals[k-1] = val;
            push_heap(vals.begin(), vals.end(), comp());
        }
        return vals.front();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
