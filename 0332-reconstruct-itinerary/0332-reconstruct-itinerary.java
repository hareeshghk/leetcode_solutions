class Solution {
    Map<String, PriorityQueue<String>> graph;
    List<String> route;
    public List<String> findItinerary(List<List<String>> tickets) {
        route = new ArrayList<>();
        graph = new HashMap<>();
        
        // Creating graph where vertices are added in lexographical ascending order.
        tickets.forEach(ticket -> {
           if (graph.get(ticket.get(0)) == null) {
               graph.put(ticket.get(0), new PriorityQueue<>());
           }
            
            graph.get(ticket.get(0)).add(ticket.get(1));
        });
        
        visit("JFK");
        return route;
    }
    
    private void visit(String root) {
        while (graph.get(root) != null && !graph.get(root).isEmpty()) {
            visit(graph.get(root).poll());
        }
        
        route.add(0, root);
    }
}