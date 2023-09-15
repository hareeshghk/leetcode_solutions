class DSU {
    int[] parent;
    int[] height;
    int n;
    public DSU(int numPoints) {
        n = numPoints;
        parent = new int[n];
        height = new int[n];
        
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            height[i] = 0;
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
        
        if (height[pa] == height[pb]) {
            height[pa]+=1;
            parent[pb] = pa;
        } else if (height[pa] < height[pb]) {
            parent[pa] = pb;
        } else {
            parent[pb] = pa;
        }
    
        return true;
    }
}

class Solution {
    public int minCostConnectPoints(int[][] points) {
        // Capture all distances and points mapped to them
        Map<Integer, List<Pair<Integer, Integer>>> distanceMap = new TreeMap<>();
        int numPoints = points.length;
        for (int i = 0; i < numPoints; ++i) {
            for (int j = i+1; j < numPoints; ++j) {
                int distance = getManhattanDistance(points[i], points[j]);
                
                if (!distanceMap.containsKey(distance)) {
                    distanceMap.put(distance, new ArrayList<>());
                }
                
                distanceMap.get(distance).add(new Pair<Integer, Integer>(i, j));
            }
        }
        
        int[] minCost = new int[1];
        minCost[0] = 0;
        DSU dsu = new DSU(numPoints);
        // Go though distances in sorted added and apply kruskals algorithm
        for (Map.Entry<Integer, List<Pair<Integer, Integer>>> mapEntry : distanceMap.entrySet()) {
            int distance = mapEntry.getKey();
            List<Pair<Integer, Integer>> pairs = mapEntry.getValue();
            
            pairs.forEach(pair -> {
               int start = pair.getKey();
               int end = pair.getValue();
                if (dsu.unionFind(start, end) == true) {
                    minCost[0] += distance;
                }
            });
        }
        
        return minCost[0];
    }
    
    private int getManhattanDistance(int[] p1, int[] p2) {
        return Math.abs(p1[0]-p2[0])+Math.abs(p1[1]-p2[1]);
    }
}