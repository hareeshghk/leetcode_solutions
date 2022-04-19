class BoundedBlockingQueue {
    mutex mtx;
    condition_variable cvpush, cvpop;
    queue<int> q;
    int capacity;
public:
    BoundedBlockingQueue(int capacity) {
        this->capacity = capacity;
    }
    
    void enqueue(int element) {
        unique_lock<mutex> ul(mtx);
        cvpush.wait(ul, [this](){return q.size() < capacity;});
        q.push(element);
        cvpop.notify_one();
    }
    
    int dequeue() {
        unique_lock<mutex> ul(mtx);
        cvpop.wait(ul, [this](){return q.size() > 0;});
        int val = q.front();
        q.pop();
        cvpush.notify_one();
        return val;
    }
    
    int size() {
        lock_guard<mutex> ul(mtx);
        return q.size();
    }
};