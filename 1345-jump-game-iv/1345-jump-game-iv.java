class Solution {
    public int minJumps(int[] arr) {
        int n = arr.length;
        
        Map<Integer, List<Integer>> finder = new HashMap<>();
        
        for (int i = 0; i < n; ++i) {
            finder.computeIfAbsent(arr[i], v -> new ArrayList<Integer>());
            finder.get(arr[i]).add(i);
        }
        
        boolean[] visited = new boolean[n];
        
        Queue<Integer> current = new LinkedList<Integer>();
        
        current.add(0);
        visited[0] = true;
        
        int steps = 0;
        while (!current.isEmpty()) {
            int x = current.size();
            
            for (int i = 0; i < x; ++i) {
                int index = current.poll();
                if (index == n-1) {
                    return steps;
                }
                
                if ((index + 1) < n && !visited[index+1]) {
                    visited[index + 1] = true;
                    current.add(index + 1);
                }
                
                if (index - 1 >= 0 && !visited[index-1]) {
                    visited[index - 1] = true;
                    current.add(index - 1);
                }
                
                for (int pos : finder.get(arr[index])) {
                    if (!visited[pos]) {
                        visited[pos] = true;
                        current.add(pos);
                    }
                }
                
                // Clearing the list so we won't stuck in forloop at step 39 every time. 
                finder.get(arr[index]).clear();
            }
            steps++;
        }
        return -1;
    }
}