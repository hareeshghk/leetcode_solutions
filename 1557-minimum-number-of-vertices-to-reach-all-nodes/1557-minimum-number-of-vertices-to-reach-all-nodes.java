class Solution {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
        Set<Integer> inOrder = IntStream.rangeClosed(0, n-1).boxed().collect(Collectors.toSet());
        edges.forEach(edge -> {
            inOrder.remove(edge.get(1));
        });
        
        return inOrder.stream().collect(Collectors.toList());
    }
}