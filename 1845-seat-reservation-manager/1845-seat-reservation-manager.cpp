class SeatManager {
    priority_queue<int, vector<int>, greater<int>> minheap;
public:
    SeatManager(int n) {
        minheap = priority_queue<int, vector<int>, greater<int>>();
        
        for (int i = 1; i <= n; ++i) {
            minheap.push(i);
        }
    }
    
    int reserve() {
        int room = minheap.top();
        minheap.pop();
        return room;
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