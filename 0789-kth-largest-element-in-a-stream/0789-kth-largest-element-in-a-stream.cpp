#include <queue>
#include <vector>
using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        pq = priority_queue<int, vector<int>, greater<>>();
        this->k = k;

        for (auto num : nums) {
            if (pq.size() < k) {
                pq.push(num);
            } else {
                if (num > pq.top()) {
                    pq.pop();
                    pq.push(num);
                }
            }
        }
    }
    
    int add(int val) {
        if (pq.size() < k) {
            pq.push(val);
        } else {
            if (val > pq.top()) {
                    pq.pop();
                    pq.push(val);
                }
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
