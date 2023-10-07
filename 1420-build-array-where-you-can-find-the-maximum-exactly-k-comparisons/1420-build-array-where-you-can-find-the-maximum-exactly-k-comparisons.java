class Solution {
    int[][][] seen;
    private static Integer MOD = 1000000007;
    public int numOfArrays(int n, int m, int k) {
        int answer = 0;
        seen = new int[m+1][n][k+1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 0; j < n; ++j) {
                Arrays.fill(seen[i][j], -1);
            }
        }
        for (int i = 1; i <= m; ++i) {
            answer = (answer + numWays(i, 1, k-1, m, n))%MOD;
        }
        return answer;
    }
    
    int numWays(int prev, int curIdx, int k, int m, int n) {
        if (k <  0) return 0;
        
        if (curIdx == n) {
            if (k == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        
        if (seen[prev][curIdx][k] != -1) {
            return seen[prev][curIdx][k];
        }
        
        int answer = 0;
        for (int i = 1; i <= prev; ++i) {
            answer = (answer + numWays(prev, curIdx+1, k, m, n))%MOD;
        }
        
        for (int i = prev+1; i <= m; ++i) {
            answer = (answer + numWays(i, curIdx+1, k-1, m, n))%MOD;
        }
        seen[prev][curIdx][k] = answer;
        return answer;
    }
}