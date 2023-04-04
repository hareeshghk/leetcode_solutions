class Solution {
    public int partitionString(String s) {
        boolean[] visited = new boolean[26];
        
        int answer = 0;
        int ws = 0, we = 0;
        
        for (we = 0; we < s.length(); ++we) {
            if (visited[s.charAt(we)-'a'] == true) {
                answer++;
                while (ws < we) {
                    visited[s.charAt(ws++)-'a'] = false;
                }
            }
            
            visited[s.charAt(we)-'a'] = true;
        }
        answer++;
        
        return answer;
    }
}