class Solution {
    int mod = 1000000007;
    
    public int numSubseq(int[] nums, int target) {
        int n = nums.length;
        
        /// Sorting numbers.
        Arrays.sort(nums);
        
        // Precompute the value of 2 to the power of each value and also apply mod because 2^n can go beyond n.
        // (a^n)%mod = ((a^(n-1))%mod * a)%mod  
        int[] power = new int[n];
        power[0] = 1;
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % mod;
        }
        
        int answer = 0;
        int left = 0, right = n - 1;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                answer = (answer + power[right - left])%mod;
                left++;
            } else {
                right--;
            }
        }
        
        return answer;
    }
}