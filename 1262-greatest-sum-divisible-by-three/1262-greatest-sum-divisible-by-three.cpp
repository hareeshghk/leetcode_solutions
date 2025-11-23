class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int ans = 0;
        
        vector<int> ones, twos;
        int onesSum = 0, twosSum = 0;
        for (auto num : nums) {
            if (num %3 == 0) {
                ans += num;
            } else if (num %3 == 1) {
                ones.push_back(num);
                onesSum += num;
            } else {
                twos.push_back(num);
                twosSum += num;
            }
        }

        sort(ones.begin(), ones.end());
        sort(twos.begin(), twos.end());
        int m = ones.size();
        int n = twos.size();
        int val = 0;
        for (int cntb = m-2; cntb <= m; ++cntb) {
            if (cntb >= 0) {
                for (int cntc = n-2; cntc <= n; ++cntc) {
                    if (cntc >= 0 && (cntb - cntc)%3 == 0) {
                        val = max(val, getSum(ones, cntb, onesSum) + getSum(twos, cntc, twosSum));
                    }
                }
            }
        }
        return ans+val;
    }
private:
    inline int getSum(vector<int> &arr, int c, int totalSum) {
        int remove = arr.size()-c;

        for (int i = 0; i < remove; ++i) {
            totalSum -= arr[i];
        }
        return totalSum;
    }
};

//divided by 3 have 3 reminders
// 0,1,2 we can take all 0's 1's and 2's we need to careful on which to choose
// 1
// 5,8
// dp[i][j] = max(dp[i-3][j] , dp[i][j-3], dp[i-1][j-1])