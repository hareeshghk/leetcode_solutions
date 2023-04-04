class Solution {
    public int partitionString(String s) {
        int[] visited = new int[26];
        Arrays.fill(visited, -1);
        int answer = 0;
        int subStrStart = 0;
        
        for (int we = 0; we < s.length(); ++we) {
            if (visited[s.charAt(we)-'a'] >= subStrStart) {
                answer++;
                subStrStart = we;
            }
            
            visited[s.charAt(we)-'a'] = we;
        }
        answer++;
        
        return answer;
    }
}