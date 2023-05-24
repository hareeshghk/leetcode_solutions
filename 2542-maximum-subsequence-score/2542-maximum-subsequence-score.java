class Solution {
    public long maxScore(int[] nums1, int[] nums2, int k) {
        int n = nums1.length;
        
        int[][] nums2WithIndices = new int[n][2];
        
        for (int i = 0; i < n; ++i) {
            nums2WithIndices[i] = new int[]{nums2[i], nums1[i]};
        }
        
        Arrays.sort(nums2WithIndices, (a, b) -> b[0]-a[0]);
        
        
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        long currentSum = 0;
        long answer = 0;
        for (int i = 0; i < k && i < n; ++i) {
            currentSum += nums2WithIndices[i][1];
            minHeap.add(nums2WithIndices[i][1]);
        }
        
        if (n-k >= 0) {
            answer = currentSum * nums2WithIndices[k-1][0];
        }
        
        for (int i = k; i < n; ++i) {
            int currentMin = nums2WithIndices[i][0];
            int currentNum = nums2WithIndices[i][1];
            if (currentNum > minHeap.peek()) {
                currentSum += currentNum - minHeap.poll();
                minHeap.add(currentNum);
            }
            
            answer = Math.max(answer, currentSum * currentMin);
        }
        
        return answer;
    }
}