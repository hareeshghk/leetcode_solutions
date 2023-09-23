class Solution {
    public int longestStrChain(String[] words) {
        int numWords = words.length;
        if (numWords == 0) return 0;
        
        // Sort the words by length
        Arrays.sort(words, (a, b) -> a.length()-b.length());

        
        // Iterate from left to right and at each word find the maximum length of chain formed by that word and ended at that word. then store that length in an array aganinst words index.
        Map<String, Integer> seenWords = new HashMap<>();
        
        int answer = 1;
        
        int[] dp = new int[numWords];
        
        for (int i = 0; i < numWords; ++i) {
            dp[i] = 1;
            
            String word = words[i];
            
            // Generating strings from word by removing each letter
            for (int j = 0; j < word.length(); ++j) {
                String newWord = word.substring(0, j) + word.substring(j+1, word.length());
                
                if (seenWords.containsKey(newWord) == true) {
                    int previousWordIndex = seenWords.get(newWord);
                    
                    dp[i] = Math.max(dp[i], dp[previousWordIndex] + 1);
                }
            }
            
            seenWords.put(word, i);
            answer = Math.max(answer, dp[i]);
        }
        
        // Return the maximum value in that array where max lengths are stored.
        return answer;
    }
}