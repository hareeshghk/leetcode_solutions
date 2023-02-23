class Solution {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int n = profits.length;
        
        int[][] values = new int[n][];
        
        for (int i = 0; i < n; ++i) {
            values[i] = new int[2];
            values[i][0] = capital[i];
            values[i][1] = profits[i];
        }
        
        // sort by capitals
        Arrays.sort(values, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return Integer.compare(a[0], b[0]);
            }
        });
        
        // Max heap
        PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>(Collections.reverseOrder());
        
        int index = 0;
        
        while (index < n && values[index][0] <= w) {
            maxHeap.add(values[index][1]);
            index++;
        }
        
        int currentCapital = w;
        
        while (!maxHeap.isEmpty() && k-- > 0) {
            int profit = maxHeap.poll();
            
            currentCapital += profit;
            
            while (index < n && values[index][0] <= currentCapital) {
                maxHeap.add(values[index][1]);
                ++index;
            }
        }
        return currentCapital;
    }
}