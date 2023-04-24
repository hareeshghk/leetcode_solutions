class Solution {
    public int lastStoneWeight(int[] stones) {
        Queue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        for (int stone : stones) {
            pq.add(stone);
        }
        
        while (pq.size() > 1) {
            int y = pq.poll();
            int x = pq.poll();
            
            if (x==y) {
                continue;
            } else {
                pq.add(y-x);
            }
        }
        
        return (pq.size()==0)?0:pq.poll();
    }
}