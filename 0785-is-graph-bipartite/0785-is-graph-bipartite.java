class Solution {
    int[] colours;
    boolean[] visited;
    public boolean isBipartite(int[][] graph) {
        // graph should be able to get coloured with 2 colours for it to be bipartitie.
        int c1=1,c2=2;
        
        int n = graph.length;
        colours = new int[n];
        Arrays.fill(colours, 0);
        visited = new boolean[n];
        Arrays.fill(visited, false);
        
        colours[0] = 1;
        boolean answer = true;
        for (int i = 0; i < n; ++i) {
            if (visited[i] == false) {
                answer = answer && isBipart(graph, i, n);
            }
        }
        return answer;
    }
    
    private boolean isBipart(int[][] graph, int index, int n) {
        Queue<Integer> q = new LinkedList<>();
        
        q.offer(index);
        colours[index] = 1;
        while (!q.isEmpty()) {
            int front = q.poll();
            if (visited[front]) {
                continue;
            }
            
            for (int i = 0; i < graph[front].length; ++i) {
                    if (colours[graph[front][i]] != 0 && colours[graph[front][i]] != 3-colours[front]) {
                        return false;
                    }
                    
                    colours[graph[front][i]] = 3-colours[front];
                    q.offer(graph[front][i]);
            }
            
            visited[front] = true;
        }
        return true;
    }
}