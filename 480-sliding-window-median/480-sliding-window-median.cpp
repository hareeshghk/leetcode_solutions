
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

class medians {
    multiset<int, greater<int>> maxheap;
    multiset<int> minheap;
public:
    void insert(int val) {
        if (maxheap.empty() || val <= *(maxheap.begin())) {
            maxheap.insert(val);
        } else {
            minheap.insert(val);
        }
        rebalanceheaps();
    }
    
    void erase(int val) {
        if (val <= *(maxheap.begin())) {
            maxheap.erase(find(maxheap.begin(), maxheap.end(), val));
        } else {
            minheap.erase(find(minheap.begin(), minheap.end(), val));
        }
        rebalanceheaps();
    }
    
    double getmedian() {
        if (maxheap.size() > minheap.size()) {
            return *maxheap.begin();
        } else {
            return ((double)*(maxheap.begin()) + (double)*(minheap.begin()))*0.5;
        }
    }
    
    void rebalanceheaps() {
        if (maxheap.size() > minheap.size()+1) {
            minheap.insert(*(maxheap.begin()));
            maxheap.erase(maxheap.begin());
        } else if (maxheap.size() < minheap.size()) {
            maxheap.insert(*(minheap.begin()));
            minheap.erase(minheap.begin());
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