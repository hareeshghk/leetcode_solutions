class StockSpanner {
    stack<pair<int,int>> st;
    int days;
public:
    StockSpanner() {
        days = 0;
    }
    
    int next(int price) {
        int result = 1;
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        
        if (!st.empty()) {
            result = days - st.top().second;
        } else {
            result = days+1;
        }
        st.push(make_pair(price, days));
        days++;
        return result;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */