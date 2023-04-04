class Solution {
    public int partitionString(String s) {
        Set<Character> visited = new HashSet<>();
        
        int answer = 0;
        
        for (char ch : s.toCharArray()) {
            if (visited.contains(ch)) {
                visited.clear();
                answer++;
            }
            
            visited.add(ch);
        }
        answer++;
        
        return answer;
    }
}