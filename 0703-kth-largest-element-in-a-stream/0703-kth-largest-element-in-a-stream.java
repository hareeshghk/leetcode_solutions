class KthLargest {
    private PriorityQueue<Integer> minHeap, maxHeap;
    private int _k;
    public KthLargest(int k, int[] nums) {
        maxHeap = new PriorityQueue<Integer>(Collections.reverseOrder());
        minHeap = new PriorityQueue<Integer>();
        _k = k;
        
        for (int i = 0; i < nums.length; ++i) {
            if (minHeap.size() < k) {
                minHeap.add(nums[i]);
            } else {
                if (nums[i] <= minHeap.peek()) {
                    maxHeap.add(nums[i]);
                } else {
                    maxHeap.add(minHeap.poll());
                    minHeap.add(nums[i]);
                }
                
            }
        }        
    }
    
    public int add(int val) {
        if (minHeap.isEmpty() || minHeap.size() < _k) {
            minHeap.add(val);
        } else if (val <= minHeap.peek()) {
            maxHeap.add(val);
        } else {
            maxHeap.add(minHeap.poll());
            minHeap.add(val);
        }
        return minHeap.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */