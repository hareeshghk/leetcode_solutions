#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        typedef pair<int,int> cell;
        priority_queue<cell> profitheap;
        priority_queue<cell, vector<cell>, greater<cell>> capitalheap;
        
        for (int i = 0; i < capital.size(); ++i) {
            if (capital[i] <= w) {
                profitheap.push(cell(profits[i], i));
            } else {
                capitalheap.push(cell(capital[i], i));
            }
        }
        
        while (k-- && !profitheap.empty()) {
            auto cur = profitheap.top();
            profitheap.pop();
            w += cur.first;
            while (!capitalheap.empty() && w >= capitalheap.top().first) {
                profitheap.push(cell(profits[capitalheap.top().second], capitalheap.top().second));
                capitalheap.pop();
            }
        }
        return w;
    }
};
