class Solution {
    public String removeDuplicateLetters(String s) {
        int n = s.length();
        
        if (n == 0) return s;
        
        Stack<Character> st = new Stack<>();
        Map<Character, Integer> lastOccurrence = new HashMap<>();
        Set<Character> seen = new HashSet<>();
        
        for (int i = 0; i < n; ++i) {
            lastOccurrence.put(s.charAt(i), i);
        }
        
        for (int i = 0; i < n; ++i) {
            if (!seen.contains(s.charAt(i))) {
                while (!st.isEmpty() && st.peek() > s.charAt(i) && lastOccurrence.get(st.peek()) > i) {
                seen.remove(st.pop());
                }
                st.push(s.charAt(i));
                seen.add(s.charAt(i));
            }
        }
        
        StringBuilder answer = new StringBuilder();
        
        while (!st.isEmpty()) {
            answer.append(st.pop());
        }
        
        return answer.reverse().toString();
    }
}