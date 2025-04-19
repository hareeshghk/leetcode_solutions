class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int maxAttainable = 0;
        int answer = 0;
        int n = coins.size();
        for (int i = 0; i < n && maxAttainable < target; ++i) {
            while(maxAttainable < target && maxAttainable + 1 < coins[i]) {
                maxAttainable += (maxAttainable+1);
                answer++;
            }
            maxAttainable += coins[i];
        }

        while (maxAttainable < target) {
            maxAttainable += (maxAttainable+1);
            answer++;
        }
        return answer;
    }
};