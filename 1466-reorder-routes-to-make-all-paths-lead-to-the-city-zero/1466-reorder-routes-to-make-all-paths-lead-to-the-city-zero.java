class Solution {
    public int minReorder(int n, int[][] connections) {
        ArrayList<ArrayList<Integer>> graph, graphRev;
        
        graph = new ArrayList<ArrayList<Integer>>(n);
        graphRev = new ArrayList<ArrayList<Integer>>(n);
        
        for (int i = 0; i < n; ++i) {
            graph.add(new ArrayList<>());
            graphRev.add(new ArrayList<>());
        }
        
        
        for (int[] connection : connections) {
            graph.get(connection[1]).add(connection[0]);
            graphRev.get(connection[0]).add(connection[1]);
        }
        
        int[] parent = new int[n];
        
        Queue<Integer> bfsQueue = new LinkedList<>();
        
        bfsQueue.offer(0);
        parent[0] = -1;
        
        int answer = 0;
        
        while (!bfsQueue.isEmpty()) {
            int root = bfsQueue.poll();
            int p = parent[root];
            
            for (Integer child : graph.get(root)) {
                if (child == p) continue;
                bfsQueue.offer(child);
                parent[child] = root;
            }
            
            for (Integer child : graphRev.get(root)) {
                if (child == p) continue;
                bfsQueue.offer(child);
                parent[child] = root;
                ++answer;
            }
        }
        
        return answer;
    }
}