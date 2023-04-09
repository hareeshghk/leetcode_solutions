class Solution {
    public int largestPathValue(String colors, int[][] edges) {
        int n = colors.length();
        
        int[] inDegree = new int[n];
        
        int[][] counter = new int[n][26];
        
        int visited = 0, answer = -1;
        
        
        
        HashMap<Integer, ArrayList<Integer>> graph = new HashMap<>();
        
        
        for (int[] edge : edges) {
            graph.computeIfAbsent(edge[0], k -> new ArrayList<>()).add(edge[1]);
            inDegree[edge[1]]++;
        }
        
        Queue<Integer> topoQ = new LinkedList<>();
        
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                topoQ.offer(i);
            }
        }
        
        
        
        while (!topoQ.isEmpty()) {
            int curr = topoQ.poll();
            
            answer = Math.max(answer, ++counter[curr][colors.charAt(curr)-'a']);
            
            ArrayList<Integer> neigbors = graph.getOrDefault(curr, null);
            
            if (neigbors != null) {
                for (Integer neighbor : neigbors) {
                    inDegree[neighbor]--;
                    
                    for (int i = 0; i < 26; ++i) {
                        counter[neighbor][i] = Math.max(counter[neighbor][i], counter[curr][i]);
                    }
                    
                    if (inDegree[neighbor] == 0) {
                        topoQ.offer(neighbor);
                    }
                }
            }
            visited++;
        }
        
        // If cycle is present.
        if (visited != n) {
            return -1;
        }
        
        return answer;
    }
}