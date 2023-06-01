class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        
        if (grid[0][0] == 1) return -1;
        
        
        int[][] dirs = new int[][]{ new int[]{-1,0}, new int[]{-1,-1}, new int[]{-1,1}, new int[]{0,-1}, new int[]{0,1}, new int[]{1,-1}, new int[]{1,0}, new int[]{1,1}};
        
        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        grid[0][0] = 1;
        
        int curx, cury, nextx, nexty;
        
        while (!q.isEmpty()) {
            int cur = q.poll();
            
            curx = cur/n;
            cury = cur%n;
            
            if (curx==n-1 && cury==n-1) return grid[curx][cury];

            for (int[] dir : dirs) {
                nextx = curx+dir[0];
                nexty = cury+dir[1];
                if (((nextx>=0 && nextx<n) &(nexty>=0 && nexty<n)) && grid[nextx][nexty] == 0) {
                    q.offer((nextx*n)+nexty);
                    grid[nextx][nexty] = grid[curx][cury]+1;
                }
            }
        }
        return -1;
    }
}