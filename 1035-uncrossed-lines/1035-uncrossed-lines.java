class Solution {
    int[][] dp;
    public int maxUncrossedLines(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        dp = new int[m][n];
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = -1;
            }
        }
        return solve(m-1, n-1, nums1, nums2);
    }
    
    int solve(int i, int j, int[] nums1, int[] nums2) {
        if (i < 0 || j < 0) {
            return 0;
        }
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        if (nums1[i] == nums2[j]) {
            dp[i][j] = 1 + solve(i-1, j-1, nums1, nums2);
        } else {
            dp[i][j] = Math.max(solve(i-1, j, nums1, nums2), solve(i, j-1, nums1, nums2));
        }
        return dp[i][j];
    }
}