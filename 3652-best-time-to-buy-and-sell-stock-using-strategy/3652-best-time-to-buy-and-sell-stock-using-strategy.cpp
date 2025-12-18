class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<vector<long long>> prefixSums = vector<vector<long long>>(n, vector<long long>(3, 0));

        vector<long long> minusone = vector<long long>(n, 0);
        vector<long long> zero = vector<long long>(n, 0);
        vector<long long> plusone = vector<long long>(n, 0);
        
        long long overallSum = prices[0]*strategy[0];
        prefixSums[0][strategy[0]+1] = prices[0];

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 3; ++j) {
                prefixSums[i][j] = prefixSums[i-1][j];
            }
            prefixSums[i][strategy[i]+1] += prices[i];
            overallSum += (strategy[i]*prices[i]);
        }

        long long answer = overallSum, currentValue;
        int mid, end;
        for (int i=0; i+k-1 < n; ++i) {
            int mid = i+(k/2)-1;
            int end = i+k-1;

            currentValue = overallSum;
            currentValue += prefixSums[mid][0]-(i==0?0:prefixSums[i-1][0]);
            currentValue -= prefixSums[mid][2]-(i==0?0:prefixSums[i-1][2]);

            currentValue += 2*(prefixSums[end][0]-prefixSums[mid][0]);
            currentValue += prefixSums[end][1] - prefixSums[mid][1];

            answer = max(answer, currentValue);
        }

        return answer;
    }
};