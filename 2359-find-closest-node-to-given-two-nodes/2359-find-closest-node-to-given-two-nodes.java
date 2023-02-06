class Solution {
    public int closestMeetingNode(int[] edges, int node1, int node2) {
        int n = edges.length;

        int[] d1 = new int[n];
        int[] d2 = new int[n];

        for (int i = 0; i < n; ++i) {
            d1[i] = Integer.MAX_VALUE;
            d2[i] = Integer.MAX_VALUE;
        }

        traverse(node1, edges, d1, n);
        traverse(node2, edges, d2, n);

        int mindistance=Integer.MAX_VALUE, minnode=-1;

        for (int i = 0; i < n; ++i) {
            if (Math.max(d1[i], d2[i]) < mindistance) {
                mindistance = Math.max(d1[i], d2[i]);
                minnode = i;
            }
        }

        return minnode;
    }

    private void traverse(int root, int[] edges, int[] d, int n) {
        Queue<Integer> q = new LinkedList<>();
        q.offer(root);

        Boolean[] visited = new Boolean[n];
        Arrays.fill(visited, Boolean.FALSE);
        d[root] = 0;

        while(!q.isEmpty()) {
            int cur = q.remove();
            if(visited[cur]) continue;

            visited[cur] = true;

            int next = edges[cur];

            if (next != -1 && !visited[next]) {
                q.offer(next);
                d[next] = 1 + d[cur];
            }
        }
    }
}