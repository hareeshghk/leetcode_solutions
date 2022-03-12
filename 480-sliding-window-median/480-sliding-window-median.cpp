
template <typename T, class container = vector<T>, class comparator = less<T>>
class mypriority_queue: public priority_queue<T, container, comparator> {
public:
    bool remove(T val) {
        auto pos = find(this->c.begin(), this->c.end(), val);
        if (pos == this->c.end()) return false;
        
        this->c.erase(pos);
        
        make_heap(this->c.begin(), this->c.end(), this->comp);
        return true;
    }
};

typedef long long int lli;

class medians {
    mypriority_queue<lli> maxheap;
    mypriority_queue<lli, vector<lli>, greater<lli>> minheap;
public:
    void insert(int val) {
        if (maxheap.empty() || val <= maxheap.top()) {
            maxheap.push(val);
        } else {
            minheap.push(val);
        }
        rebalanceheaps();
    }
    
    void erase(int val) {
        if (val <= maxheap.top()) {
            maxheap.remove(val);
        } else {
            minheap.remove(val);
        }
        rebalanceheaps();
    }
    
    double getmedian() {
        if (maxheap.size() > minheap.size()) {
            return maxheap.top();
        } else {
            return (maxheap.top() + minheap.top())*0.5;
        }
    }
    
    void rebalanceheaps() {
        if (maxheap.size() > minheap.size()+1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        } else if (maxheap.size() < minheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        int n= nums.size();
        if (n < k) return vector<double>{};
        
        medians m;
        
        vector<double> result;
        for (int i = 0; i < n; i++) {
            m.insert(nums[i]);
            if (i >=k-1) {
                result.push_back(m.getmedian());
                m.erase(nums[i-k+1]);
            }
        }
        return result;
    }
};