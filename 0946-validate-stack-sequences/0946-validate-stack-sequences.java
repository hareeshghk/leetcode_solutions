class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int popped_itr = 0;
        int pushed_itr = 0;
        int n = pushed.length;
        
        
        for (int i = 0; i < n; ++i) {
            pushed[pushed_itr++] = pushed[i];
            
            while (pushed_itr > 0 && pushed[pushed_itr-1] == popped[popped_itr]) {
                pushed_itr--;
                popped_itr++;
            }
        }
        
        return pushed_itr == 0;
    }
}