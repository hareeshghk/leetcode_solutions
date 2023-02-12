class Solution {
    long answer;
    int numSeatsInaCar;
    public long minimumFuelCost(int[][] roads, int seats) {
        // Given there are n-1 roads.
        int n = roads.length + 1;
        
        if (n == 1) return 0;
        
        // Structure to store the graph (parent -> list of childs)
        HashMap<Integer, ArrayList<Integer>> graph = new HashMap<>();
        
        
        for (int[] road : roads) {
            graph.computeIfAbsent(road[0], v -> new ArrayList<>()).add(road[1]);
            graph.computeIfAbsent(road[1], v -> new ArrayList<>()).add(road[0]);
        }
        
        // initializing anwer
        answer = 0;
        
        // From given input
        numSeatsInaCar = seats;
        
        
        numNodes(0, -1, graph);
        
        return answer;
    }
    
    private long numNodes(int root, int parent, HashMap<Integer, ArrayList<Integer>> graph) {
        if (parent != -1 && graph.get(root).size() == 1) {
            return 1;
        }
        
        long totalNodes = 1, currentNodes;
        
        for (int child : graph.get(root)) {
            if (child == parent) continue;
            currentNodes = numNodes(child, root, graph);
            answer += currentNodes/numSeatsInaCar;
            if (currentNodes % numSeatsInaCar != 0) answer++;
            totalNodes += currentNodes;
        }
        return totalNodes;
    }
}