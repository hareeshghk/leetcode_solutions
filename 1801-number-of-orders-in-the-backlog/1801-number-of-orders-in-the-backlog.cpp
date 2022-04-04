class Solution {
public:
    struct mincost {
        bool operator()(const pair<int,int> &a, const pair<int,int> &b) {
            return a.first > b.first;
        }
    };
    struct maxcost {
        bool operator()(const pair<int,int> &a, const pair<int,int> &b) {
            return a.first < b.first;
        }
    };
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, mincost> min_heap_sell_order;
        priority_queue<pair<int,int>, vector<pair<int,int>>, maxcost> max_heap_buy_order;
        
        int backlog_orders = 0;
        const int mod = 1000000007;
        for (auto order : orders) {
            if (order[2] == 0) {
                max_heap_buy_order.push(make_pair(order[0], order[1]));
            } else {
                min_heap_sell_order.push(make_pair(order[0], order[1]));
            }
            
            while ((!min_heap_sell_order.empty() && !max_heap_buy_order.empty()) && (max_heap_buy_order.top().first >= min_heap_sell_order.top().first)) {
                auto buy_order = max_heap_buy_order.top();
                auto sell_order = min_heap_sell_order.top();
                max_heap_buy_order.pop();
                min_heap_sell_order.pop();
                // if we can match all match
                if (buy_order.second > sell_order.second) {
                    buy_order.second -= sell_order.second;
                    max_heap_buy_order.push(buy_order);
                } else if (buy_order.second < sell_order.second) {
                    sell_order.second -= buy_order.second;
                    min_heap_sell_order.push(sell_order);
                }
            }
        }
        
        while (!min_heap_sell_order.empty()) {
            backlog_orders = (backlog_orders + min_heap_sell_order.top().second)%mod;
            min_heap_sell_order.pop();
        }
        
        while (!max_heap_buy_order.empty()) {
            backlog_orders = (backlog_orders + max_heap_buy_order.top().second)%mod;
            max_heap_buy_order.pop();
        }
        return backlog_orders;
    }
};