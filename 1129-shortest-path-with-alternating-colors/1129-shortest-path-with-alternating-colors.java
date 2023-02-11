class Solution {
    public int[] shortestAlternatingPaths(int n, int[][] redEdges, int[][] blueEdges) {
        int[] redanswer = new int[n];
        int[] blueanswer = new int[n];

        for (int i = 0; i < n; ++i) {
            redanswer[i] = Integer.MAX_VALUE;
            blueanswer[i] = Integer.MAX_VALUE;
        }

        redanswer[0] = 0;
        blueanswer[0] = 0;

        for (int i = 0; i < n; ++i) {
            for (int[] redEdge : redEdges) {
                if (blueanswer[redEdge[0]] != Integer.MAX_VALUE) {
                    if (blueanswer[redEdge[0]] + 1 < redanswer[redEdge[1]]) {
                        redanswer[redEdge[1]] = blueanswer[redEdge[0]] + 1;
                    }
                }
            }

            for (int[] blueEdge : blueEdges) {
               if (redanswer[blueEdge[0]] != Integer.MAX_VALUE) {
                    if (redanswer[blueEdge[0]] + 1 < blueanswer[blueEdge[1]]) {
                        blueanswer[blueEdge[1]] = redanswer[blueEdge[0]] + 1;
                    }
                } 
            }
        }

        for (int i = 0; i < n; ++i) {
            redanswer[i] = Math.min(redanswer[i], blueanswer[i]);

            if(redanswer[i] == Integer.MAX_VALUE) redanswer[i] = -1;
        }
        return redanswer;
    }
}