class MyPair {
    Integer val1;
    Double val2;
    
    public MyPair(Integer v1, Double v2) {
        val1 = v1;
        val2 = v2;
    }
    
    public Integer getFirst() {
        return val1;
    }
    
    public Double getSecond() {
        return val2;
    }
    
    public void setFirst(Integer v1) {
        val1 = v1;
    }
    
    public void setSecond(Double v2) {
        val2 = v2;
    }
}


class Solution {
    List<MyPair> distances;
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        // Assign each string to a index.
        final Map<String, Integer> stringToIntMap = new HashMap<>();
        AtomicInteger indexer = new AtomicInteger(0);
        final Map<Integer, List<MyPair>> graph = new HashMap<>();
        
        for (int i = 0; i < equations.size(); ++i) {
            List<String> equation = equations.get(i);
            int src = stringToIntMap.computeIfAbsent(equation.get(0), k -> indexer.getAndIncrement());
            int dst = stringToIntMap.computeIfAbsent(equation.get(1), k -> indexer.getAndIncrement());
            graph.computeIfAbsent(src, k -> new ArrayList<>()).add(new MyPair(dst, values[i]));
            graph.computeIfAbsent(dst, k -> new ArrayList<>()).add(new MyPair(src, 1.0/values[i]));
        }
        
        int distinctNumberOfStrings = indexer.get();
        
        // Store parent and distance from parent to each node where distance is parent/node value.
        distances = new ArrayList<>();
        
        for (int i = 0; i < distinctNumberOfStrings; ++i) {
            distances.add(new MyPair(-1, -1.0));
        }
        
        for (int i = 0; i < distinctNumberOfStrings; ++i) {
            // not visited.
            if (distances.get(i).getFirst() == -1) {
                distances.get(i).setFirst(i);
                distances.get(i).setSecond(1.0);
                dfs(graph, i, 1, i);
            }
        }
        
        double[] answers = new double[queries.size()];
        
        for (int i = 0; i < queries.size(); ++i) {
            List<String> query = queries.get(i);
            
            String numerator = query.get(0);
            String denominator = query.get(1);
            
            if (!stringToIntMap.containsKey(numerator) || !stringToIntMap.containsKey(denominator)) {
                answers[i] = -1.0;
                continue;
            }
            
            int numeratorIndex = stringToIntMap.get(numerator);
            int denominatorIndex = stringToIntMap.get(denominator);
            
            int parentOfNumerator = distances.get(numeratorIndex).getFirst();
            int parentOfDenominator = distances.get(denominatorIndex).getFirst();
            
            if (parentOfNumerator != parentOfDenominator) {
                answers[i] = -1.0;
                continue;
            }
            
            answers[i] = distances.get(denominatorIndex).getSecond() / distances.get(numeratorIndex).getSecond();
        }
        
        return answers;
    }
    
    private void dfs(Map<Integer, List<MyPair>> graph, int root, double value, int parent) {
        for (MyPair child : graph.get(root)) {
            if (distances.get(child.getFirst()).getFirst() == -1) {
                distances.get(child.getFirst()).setFirst(parent);
                distances.get(child.getFirst()).setSecond(value * child.getSecond());
                dfs(graph, child.getFirst(), value * child.getSecond(), parent);
            }
        }
    }
}