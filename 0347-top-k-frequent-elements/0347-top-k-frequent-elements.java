class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer, Integer> mapper = new HashMap<>();
        
        for (int i = 0; i < nums.length; ++i) {
            mapper.put(nums[i], 1 + mapper.getOrDefault(nums[i], 0));
        }
        
        PriorityQueue<int[]> vals = new PriorityQueue<>((a, b) -> a[0]-b[0]);
        
        for (int key : mapper.keySet()) {
            // System.out.println(key + " " + mapper.get(key));
            if (vals.size() < k) {
                vals.add(new int[]{mapper.get(key), key});
            } else {
                if (mapper.get(key) > mapper.get(vals.peek()[1])) {
                    vals.poll();
                    vals.add(new int[]{mapper.get(key), key});
                }
            }
        }
        
        int[] answer = new int[k];
        int counter = 0;
        while (!vals.isEmpty()) {
            answer[counter++] = vals.poll()[1];
        }
        return answer;
    }
}