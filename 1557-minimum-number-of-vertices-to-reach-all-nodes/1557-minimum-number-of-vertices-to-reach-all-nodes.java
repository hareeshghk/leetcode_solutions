class Solution {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
        int[] inOrder = new int[n];
        
        edges.forEach(edge -> {
            inOrder[edge.get(1)]++;
        });
        
        List<Integer> answer = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (inOrder[i] == 0) {
                answer.add(i);
            }
        }
        
        return answer;
    }
}