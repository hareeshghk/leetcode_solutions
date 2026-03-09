class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        dp = [[[0, 0] for _ in range(one+1)] for _ in range(zero+1)]
        mod = int(1e9 + 7)

        # consequite zeroes
        for i in range(0, min(limit, zero)+1):
            dp[i][0][0] = 1
        
        # consequite ones
        for i in range(0, min(limit, one)+1):
            dp[0][i][1] = 1

        # we want dp[zero][one][0] and dp[zero][one][1]
        # dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1] - dp[i-limit-1][j][1]
        # dp[i][j][1] = dp[i][j-1][1] + dp[i][j-1][0] - dp[i][j-limit-1][0]

        for i in range(1, zero+1):
            for j in range(1, one+1):
                if i-limit-1 >= 0:
                    dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1] - dp[i-limit-1][j][1]
                else:
                    dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1]
                dp[i][j][0] = (dp[i][j][0] % mod + mod) %mod

                if j-limit-1 >= 0:
                     dp[i][j][1] = dp[i][j-1][1] + dp[i][j-1][0] - dp[i][j-limit-1][0]
                else:
                    dp[i][j][1] = dp[i][j-1][1] + dp[i][j-1][0]
                dp[i][j][1] = (dp[i][j][1] % mod + mod) %mod

        return (dp[zero][one][0] + dp[zero][one][1]) % mod