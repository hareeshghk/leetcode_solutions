class BoundedBlockingQueue {
    int capacity, current_size;
    mutex mt;
    condition_variable cvpush, cvpop;
    deque<int> dq;
public:
    BoundedBlockingQueue(int capacity) {
        current_size = 0;
        this->capacity = capacity;
    }
    
    void enqueue(int element) {
        unique_lock<mutex> ul(mt);
        cvpush.wait(ul, [this](){return current_size < capacity;});
        dq.push_front(element);
        ++current_size;
        cvpop.notify_one();
    }
    
    int dequeue() {
        unique_lock<mutex> ul(mt);
        cvpop.wait(ul, [this](){return current_size !=0;});
        int val = dq.back();
        dq.pop_back();
        --current_size;
        cvpush.notify_one();
        return val;
    }
    
    int size() {
        unique_lock<mutex> ul(mt);
        return current_size;
    }
};