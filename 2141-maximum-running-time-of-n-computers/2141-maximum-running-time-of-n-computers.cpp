class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int m  = batteries.size();
        long long totalPower = 0;

        for (auto bat : batteries) {
            totalPower += bat;
        }

        long long left = 0, right = totalPower/n;

        while (left < right) {
            long long target = right - (right-left) / 2;

            long long extra = 0;

            for (int i = 0; i < m; ++i) {
                extra += min(target, (long long)batteries[i]);
            }

            if (extra >= n * target) {
                left = target;
            } else {
                right = target-1;
            }
        }
        return left;
    }
};