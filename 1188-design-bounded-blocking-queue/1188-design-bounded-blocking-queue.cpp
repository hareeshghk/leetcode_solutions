class BoundedBlockingQueue {
    condition_variable cvpush,cvpop;
    mutex m;
    queue<int> q;
    int current_size, capacity;;
public:
    BoundedBlockingQueue(int capacity) {
        this->capacity = capacity;
        current_size = 0;
    }
    
    void enqueue(int element) {
        unique_lock<mutex> ul(m);
        cvpush.wait(ul, [this](){return current_size < capacity;});
        ++current_size;
        q.push(element);
        cvpop.notify_one();
    }
    
    int dequeue() {
        unique_lock<mutex> ul(m);
        cvpop.wait(ul, [this](){return current_size!=0;});
        --current_size;
        int val = q.front();
        q.pop();
        cvpush.notify_one();
        return val;
    }
    
    int size() {
        lock_guard<mutex> lg(m);
        return current_size;
    }
};