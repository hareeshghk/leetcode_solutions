#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        auto compare = [](int a,int b) {return a < b;};
        make_heap(stones.begin(), stones.end(), compare);
        
        int s1,s2, cursize = stones.size();
        while (cursize > 1) {
            pop_heap(stones.begin(), stones.end(), compare);
            s1 = stones[cursize-1];
            --cursize;
            stones.pop_back();
            pop_heap(stones.begin(), stones.end(), compare);
            s2 = stones[cursize-1];
            --cursize;
            stones.pop_back();
            if (s1!=s2) {
                stones.push_back(s1-s2);
                push_heap(stones.begin(), stones.end(), compare);
                ++cursize;
            }
        }
        
        if (cursize == 0) return 0;
        return stones[0];
    }
};
