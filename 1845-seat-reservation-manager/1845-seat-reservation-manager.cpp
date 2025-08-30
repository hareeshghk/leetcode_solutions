#include <queue>
#include <vector>

class SeatManager {
    priority_queue<int, vector<int>, greater<int>> minheap;
    int marker;
public:
    SeatManager(int n) {
        minheap = priority_queue<int, vector<int>, greater<int>>();
        marker = 1;
    }
    
    int reserve() {
        if (!minheap.empty()) {
            int room = minheap.top();
            minheap.pop();
            return room;
        }
        
        return marker++;
    }
    
    void unreserve(int seatNumber) {
        minheap.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
