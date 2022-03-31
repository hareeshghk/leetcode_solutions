class BoundedBlockingQueue {
    condition_variable cv;
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
        cv.wait(ul, [this](){return current_size < capacity;});
        ++current_size;
        q.push(element);
        cv.notify_all();
    }
    
    int dequeue() {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [this](){return current_size!=0;});
        --current_size;
        int val = q.front();
        q.pop();
        cv.notify_all();
        return val;
    }
    
    int size() {
        lock_guard<mutex> lg(m);
        return current_size;
    }
};