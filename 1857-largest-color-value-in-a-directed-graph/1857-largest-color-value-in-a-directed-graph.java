class Solution {
    String cs;
    public int largestPathValue(String colors, int[][] edges) {
        int n = colors.length();
        cs = colors;
        int[] counter = new int[n];
        int visited = 0;
        int[][] colourCounter = new int[n][26];
        
        HashMap<Integer, ArrayList<Integer>> graph = new HashMap<>();
        
        
        for (int[] edge : edges) {
            graph.putIfAbsent(edge[0], new ArrayList<>());
            graph.get(edge[0]).add(edge[1]);
            counter[edge[1]]++;
        }
        
        Queue<Integer> topoQ = new LinkedList<>();
        
        for (int i = 0; i < n; ++i) {
            if (counter[i] == 0) {
                topoQ.offer(i);
            }
        }
        
        int answer = -1;
        
        while (!topoQ.isEmpty()) {
            int curr = topoQ.poll();
            
            answer = Math.max(answer, ++colourCounter[curr][colors.charAt(curr)-'a']);
            
            if (graph.getOrDefault(curr, null) != null) {
                for (Integer neighbor : graph.get(curr)) {
                    counter[neighbor]--;
                    
                    for (int i = 0; i < 26; ++i) {
                        colourCounter[neighbor][i] = Math.max(colourCounter[neighbor][i], colourCounter[curr][i]);
                    }
                    
                    if (counter[neighbor] == 0) {
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