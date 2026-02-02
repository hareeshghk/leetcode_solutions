class counter {
    int n;
    long long currentSum;
    multiset<int> st1, st2;
public:
    counter(int k) {
        n = k;
        currentSum = 0;
    }

    void rebalance() {
        while (st1.size() < n && st2.size() > 0) {
            st1.emplace(*st2.begin());
            currentSum += *st2.begin();
            st2.erase(st2.begin());
        }

        while (st1.size() > n) {
            st2.emplace(*st1.rbegin());
            currentSum -= *st1.rbegin();
            st1.erase(prev(st1.end()));
        }
    }

    void add(int x) {
        if (!st2.empty() && x >= *(st2.begin())) {
            st2.emplace(x);
        } else {
            st1.emplace(x);
            currentSum += x;
        }
        rebalance();
    }

    void remove(int x) {
        if (st1.find(x) != st1.end()) {
            st1.erase(st1.find(x));
            currentSum -= x;
        } else {
            st2.erase(st2.find(x));
        }
        rebalance();
    }

    long long getSum() {
        return currentSum;
    }
};

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        counter cnt(k-2);
        for (int i = 1; i < k-1; ++i) {
            cnt.add(nums[i]);
        }

        long long ans = cnt.getSum() + nums[k-1];;

        for (int j = k; j < n; ++j) {
            int i =  j-dist-1;
            if (i > 0) {
                cnt.remove(nums[i]);
            }
            cnt.add(nums[j-1]);
            ans = min(ans, cnt.getSum() + nums[j]);
        }

        return ans + nums[0];
    }
};