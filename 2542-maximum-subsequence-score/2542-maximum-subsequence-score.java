class Solution {
    public long maxScore(int[] nums1, int[] nums2, int k) {
        int n = nums1.length;
        
        List<List<Integer>> nums2WithIndices = new ArrayList<>();
        
        for (int i = 0; i < n; ++i) {
            List<Integer> temp = new ArrayList<>();
            temp.add(nums2[i]);
            temp.add(nums1[i]);
            nums2WithIndices.add(temp);
        }
        
        Collections.sort(nums2WithIndices, new Comparator<List<Integer>>() {
            @Override
            public int compare(List<Integer> list1, List<Integer> list2) {
                return list1.get(0).compareTo(list2.get(0));
            }
        });
        
        
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        long currentSum = 0;
        long answer = 0;
        for (int i = 0; i < k && n-1-i>=0; ++i) {
            currentSum += nums2WithIndices.get(n-1-i).get(1);
            minHeap.add(nums2WithIndices.get(n-1-i).get(1));
        }
        
        if (n-k >= 0) {
            answer = currentSum * nums2WithIndices.get(n-k).get(0);
        }
        
        for (int i = n-k-1; i >= 0; --i) {
            int currentMin = nums2WithIndices.get(i).get(0);
            int currentNum = nums2WithIndices.get(i).get(1);
            if (currentNum > minHeap.peek()) {
                currentSum -= minHeap.poll();
                minHeap.add(currentNum);
                currentSum += currentNum;
            }
            
            answer = Math.max(answer, currentSum * currentMin);
        }
        
        return answer;
    }
}