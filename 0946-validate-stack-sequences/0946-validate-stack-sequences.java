class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int iter = 0;
        int n = pushed.length;
        
        Stack<Integer> st = new Stack<>();
        HashMap<Integer, Integer> indexMapper = new HashMap<>();
        
        for (int i = 0; i < n; ++i) {
            indexMapper.put(pushed[i], i);
        }
        
        for (int i = 0; i < n; ++i) {
            if (!st.isEmpty() && st.peek() == popped[i]) {
                st.pop();
                continue;
            } else {
                int origIndex = indexMapper.get(popped[i]);
                
                if (origIndex < iter) return false;
                
                while (iter < origIndex) {
                    st.push(pushed[iter]);
                    ++iter;
                }
                ++iter;
            }
        }
        
        return true;
    }
}