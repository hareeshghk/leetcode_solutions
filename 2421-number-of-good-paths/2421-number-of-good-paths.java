class DisjointUnion {
    int[] parent, rank;
    public DisjointUnion(int size) {
        parent = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    public int find(int a) {
        if (parent[a] != a) parent[a] = find(parent[a]);

        return parent[a];
    }

    public void unionfind(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) {
            return;
        } else if (rank[a] < rank[b]) {
            parent[a] = b;
        } else if (rank[b] < rank[a]) {
            parent[b] = a;
        } else {
            parent[b] = a;
            rank[a]++;
        }
    }
}

class Solution {
    // Adjacency List
    Map<Integer, List<Integer>> adjMap;
    public int numberOfGoodPaths(int[] vals, int[][] edges) {
        adjMap = new HashMap<>();

        int numNodes = vals.length;

        for (int[] edge : edges) {
            adjMap.computeIfAbsent(edge[0], v->new ArrayList<>()).add(edge[1]);
            adjMap.computeIfAbsent(edge[1], v->new ArrayList<>()).add(edge[0]);
        }

        Map<Integer, List<Integer>> valuesToNodes = new TreeMap<>();

        for (int i = 0; i < numNodes; ++i) {
            valuesToNodes.computeIfAbsent(vals[i], v->new ArrayList<>()).add(i);
        }

        DisjointUnion uf = new DisjointUnion(numNodes);

        int goodPaths = 0;

        for (int nodeVal : valuesToNodes.keySet()) {
            for (int node : valuesToNodes.get(nodeVal)) {
                if (!adjMap.containsKey(node))
                    continue;
                for (int neighbour : adjMap.get(node)) {
                    if (vals[neighbour] <= nodeVal) {
                        uf.unionfind(node, neighbour);
                    }
                }
            }

            Map<Integer, Integer> groups = new HashMap<>();

            for (int node : valuesToNodes.get(nodeVal)) {
                groups.put(uf.find(node), groups.getOrDefault(uf.find(node), 0)+1);
            }

            for (int groupKey : groups.keySet()) {
                int x = groups.get(groupKey);

                goodPaths += ((x * (x+1))/2);
            }
        }
        return goodPaths;
    }
}