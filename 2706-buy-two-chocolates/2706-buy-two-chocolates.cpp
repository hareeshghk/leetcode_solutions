#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        auto pq = priority_queue<int>();
        
        for (auto price : prices) {
            if (pq.size() < 2) {
                pq.push(price);
            } else if(price < pq.top()) {
                pq.pop();
                pq.push(price);
            }
        }
        
        int s1 = pq.top();pq.pop();
        int s2 = pq.top();pq.pop();
        
        return money-(s1+s2)>=0?money-(s1+s2):money;
    }
};
