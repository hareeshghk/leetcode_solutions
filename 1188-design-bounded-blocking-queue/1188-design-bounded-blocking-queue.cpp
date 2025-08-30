#include <deque>
using namespace std;

class BoundedBlockingQueue {
    int capacity, current_size;
    shared_mutex mt;
    condition_variable_any cvpush, cvpop;
    deque<int> dq;
public:
    BoundedBlockingQueue(int capacity) {
        current_size = 0;
        this->capacity = capacity;
    }
    
    void enqueue(int element) {
        unique_lock<shared_mutex> ul(mt);
        cvpush.wait(ul, [this](){return current_size < capacity;});
        dq.push_front(element);
        ++current_size;
        cvpop.notify_one();
    }
    
    int dequeue() {
        unique_lock<shared_mutex> ul(mt);
        cvpop.wait(ul, [this](){return current_size !=0;});
        int val = dq.back();
        dq.pop_back();
        --current_size;
        cvpush.notify_one();
        return val;
    }
    
    int size() {
        shared_lock<shared_mutex> ul(mt);
        return current_size;
    }
};
