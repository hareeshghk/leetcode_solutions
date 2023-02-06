class Solution {
    boolean[][] dp;
    List<List<String>> answer;
    public List<List<String>> partition(String s) {
        int n = s.length();
        answer = new ArrayList<>();
        dp = new boolean[n][];

        for (int i = 0; i < n; ++i) {
            dp[i] = new boolean[n];
            dp[i][i] = true;
        }

        for (int i = 0; i < n-1; ++i) {
            if (s.charAt(i) == s.charAt(i+1)) {
                dp[i][i+1] = true;
            }
        }

        for (int len = 3; len <= n; ++len) {
            for (int i = 0; (i < n) && (i+len-1 < n) ; ++i) {
                int j = i + len - 1;

                dp[i][j] = (s.charAt(i) == s.charAt(j)) && (dp[i+1][j-1]);
            }
        }

        backtrack(0, s, n, new ArrayList<String>());
        return answer;
    }

    private void backtrack(int index, String s, int n, ArrayList<String> sequences) {
        if (index >= n) {
            answer.add(new ArrayList<String>(sequences));
            return;
        }

        for (int i = index; i < n; ++i) {
            if(dp[index][i]) {
                sequences.add(s.substring(index, i+1));
                backtrack(i+1, s, n, sequences);
                sequences.remove(sequences.size()-1);
            }
        }
    }
}