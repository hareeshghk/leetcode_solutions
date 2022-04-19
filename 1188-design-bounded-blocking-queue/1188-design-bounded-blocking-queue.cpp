class BoundedBlockingQueue {
    mutex mtx;
    condition_variable cv;
    queue<int> q;
    int capacity;
public:
    BoundedBlockingQueue(int capacity) {
        this->capacity = capacity;
    }
    
    void enqueue(int element) {
        unique_lock<mutex> ul(mtx);
        cv.wait(ul, [this](){return q.size() < capacity;});
        q.push(element);
        cv.notify_one();
    }
    
    int dequeue() {
        unique_lock<mutex> ul(mtx);
        cv.wait(ul, [this](){return q.size() > 0;});
        int val = q.front();
        q.pop();
        cv.notify_one();
        return val;
    }
    
    int size() {
        unique_lock<mutex> ul(mtx);
        return q.size();
    }
};