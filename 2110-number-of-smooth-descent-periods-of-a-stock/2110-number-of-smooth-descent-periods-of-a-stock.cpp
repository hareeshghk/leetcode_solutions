class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long contiguous = 1;
        long long answer = 1;

        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i-1]-prices[i] == 1) {
                contiguous++;
            } else {
                contiguous = 1;
            }
            answer += contiguous;
        }
        return answer;
    }
};