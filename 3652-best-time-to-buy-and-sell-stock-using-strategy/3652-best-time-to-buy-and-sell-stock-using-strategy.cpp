class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> minusone = vector<long long>(n, 0);
        vector<long long> zero = vector<long long>(n, 0);
        vector<long long> plusone = vector<long long>(n, 0);
        
        long long overallSum = prices[0]*strategy[0];

        if (strategy[0] == -1) {
            minusone[0] = prices[0];
        } else if (strategy[0] == 0) {
            zero[0] = prices[0];
        } else {
            plusone[0] = prices[0];
        }

        for (int i = 1; i < n; ++i) {
            minusone[i] = minusone[i-1];
            zero[i] = zero[i-1];
            plusone[i] = plusone[i-1];

            if (strategy[i] == -1) {
                minusone[i] += prices[i];
            } else if (strategy[i] == 0) {
                zero[i] += prices[i];
            } else {
                plusone[i] += prices[i];
            }

            overallSum += (strategy[i]*prices[i]);
        }

        long long answer = overallSum, currentValue;
        for (int i=0; i+k-1 < n; ++i) {
            int start = i;
            int mid = i+(k/2)-1;
            int end = i+k-1;

            currentValue = overallSum;

            currentValue += minusone[mid]-(i==0?0:minusone[i-1]);
            currentValue -= plusone[mid]-(i==0?0:plusone[i-1]);

            currentValue += 2*(minusone[end]-minusone[mid]);
            currentValue += zero[end] - zero[mid];

            answer = max(answer, currentValue);
        }

        return answer;
    }
};