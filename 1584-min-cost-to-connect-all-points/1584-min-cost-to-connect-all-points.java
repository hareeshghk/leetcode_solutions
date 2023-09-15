class DSU {
    int[] parent;
    int n;
    public DSU(int numPoints) {
        n = numPoints;
        parent = new int[n];
        
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    
    public int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    public boolean unionFind(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        
        if (pa == pb) {
            return false;
        }
        
        parent[pb] = pa;
    
        return true;
    }
}

class Solution {
    public int minCostConnectPoints(int[][] points) {
        // Capture all distances and points mapped to them
        PriorityQueue<Pair<Integer, int[]>> distanceMinHeap = new PriorityQueue<>((a, b) -> a.getKey() - b.getKey());
        int numPoints = points.length;
        for (int i = 0; i < numPoints; ++i) {
            for (int j = i+1; j < numPoints; ++j) {
                int distance = getManhattanDistance(points[i], points[j]);
                distanceMinHeap.add(new Pair<Integer, int[]>(distance, new int[]{i, j}));
            }
        }
        
        int minCost = 0;
        DSU dsu = new DSU(numPoints);
        // Go though distances in sorted added and apply kruskals algorithm
        int numEdgesChosen = 0;
        while (!distanceMinHeap.isEmpty() && numEdgesChosen < numPoints) {
            Pair<Integer, int[]> pair = distanceMinHeap.poll();
            int[] indices = pair.getValue();
            if (dsu.unionFind(indices[0], indices[1]) == true) {
                minCost += pair.getKey();
                ++numEdgesChosen;
            }
        }
        
        return minCost;
    }
    
    private int getManhattanDistance(int[] p1, int[] p2) {
        return Math.abs(p1[0]-p2[0])+Math.abs(p1[1]-p2[1]);
    }
}