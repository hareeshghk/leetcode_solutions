#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
    unordered_map<int,int> mapper;
    int w_len;
public:
    Solution(int n, vector<int>& blacklist) {
        w_len = n - blacklist.size();
        unordered_set<int> w;
        for (int i = w_len; i < n; i++) {
            w.insert(i);
        }
        
        for (auto b : blacklist) {
            w.erase(b);
        }
        
        auto val = w.begin();
        for (auto num : blacklist) {
            if (num < w_len) {
                mapper[num] = *val;
                val++;
            }
        }
    }
    
    int pick() {
        int k = random()%w_len;
        if (mapper.find(k) == mapper.end()) return k;
        return mapper[k];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
