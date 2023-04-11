class Solution {
    public String removeStars(String s) {
        Deque<Character> dq = new ArrayDeque<>();
        
        for (char ch : s.toCharArray()) {
            if (ch == '*') {
                dq.removeLast();
            } else {
                dq.addLast(ch);
            }
        }
        
        StringBuilder builder = new StringBuilder(dq.size());
        
        while (!dq.isEmpty()) {
            builder.append(dq.removeFirst());
        }
        
        return builder.toString();
    }
}