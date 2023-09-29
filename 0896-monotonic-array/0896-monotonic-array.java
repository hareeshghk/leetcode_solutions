class Solution {
    public boolean isMonotonic(int[] nums) {
        // Check if nums is non-increasing (a >= b)
        boolean decreasing = isFollowing(nums, (a, b) -> a >= b);

        // Check if nums is non-decreasing (a <= b)
        boolean increasing = isFollowing(nums, (a, b) -> a <= b);

        // If either decreasing or increasing is true, it's monotonic.
        return decreasing || increasing;
    }

    boolean isFollowing(int[] nums, BiPredicate<Integer, Integer> comparator) {
        int n = nums.length;
        for (int i = 0; i < n - 1; i++) {
            if (!comparator.test(nums[i], nums[i + 1])) {
                return false;
            }
        }
        return true;
    }
}
