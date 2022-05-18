class MovingAverage {
public:
    queue<int> store;
    int total_size;
    double cur_sum_;
    MovingAverage(int size) {
        cur_sum_ = 0.0;
        total_size = size;
    }
    
    double next(int val) {
        cur_sum_ += val;
        
        if (store.size() == total_size) {
            cur_sum_ -= store.front();
            store.pop();
        }
        
        store.push(val);
        
        
        return cur_sum_/store.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */