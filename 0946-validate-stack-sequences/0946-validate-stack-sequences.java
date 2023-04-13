class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int popped_itr = 0;
        int n = pushed.length;
        
        Stack<Integer> st = new Stack<>();
        
        
        for (int i = 0; i < n; ++i) {
            st.push(pushed[i]);
            
            while (!st.isEmpty() && popped_itr < n && st.peek() == popped[popped_itr]) {
                st.pop();
                popped_itr++;
            }
        }
        
        return st.isEmpty();
    }
}