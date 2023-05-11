class Solution {
    public int maxUncrossedLines(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int[] dp = new int[n+1];
        
        for (int i = 0; i < m; ++i) {
            int[] temp = new int[n+1];
            for (int j = 0; j < n; ++j) {
                if (nums1[i] == nums2[j]) {
                    temp[j+1] = 1 + dp[j];
                } else {
                    temp[j+1] = Math.max(dp[j+1], temp[j]);
                }
            }
            dp = temp;
        }
        return dp[n];
    }
}