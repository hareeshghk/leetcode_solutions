class Solution {
    public int findJudge(int n, int[][] trust) {
        if (n == 1 && trust.length == 0) return 1;

        int[] count = new int[n+1];

        for (int i = 0; i < trust.length; ++i) {
            count[trust[i][0]]--;
            count[trust[i][1]]++;
        }

        for (int i = 1; i <= n; ++i) {
            if(count[i] == n-1) return i;
        }
        return -1;
    }
}
// class Solution {
//     public int findJudge(int n, int[][] trust) {
//         HashMap<Integer, Integer> counts = new HashMap<>();
//         Set<Integer> notJudge = new HashSet<>();

//         for (int i = 0; i < trust.length; ++i) {
//             counts.put(trust[i][1], counts.getOrDefault(trust[i][1], 0) + 1);
//             notJudge.add(trust[i][0]);
//         }

//         for (int i = 1; i <= n; ++i) {
//             if (counts.getOrDefault(i, 0) == n-1 && !notJudge.contains(i)) return i;
//         }
//         return -1;
//     }
// }