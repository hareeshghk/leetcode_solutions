class Solution {
    public boolean checkInclusion(String s1, String s2) {
        HashMap<Character, Integer> counter = new HashMap<>();

        for (char c : s1.toCharArray()) {
            counter.put(c, counter.getOrDefault(c, 0) + 1);
        }

        int ws = 0, we = 0;

        int matchedCount = 0;
        for(we = 0; we < s2.length(); ++we) {
            char currentChar = s2.charAt(we);
            if (!counter.containsKey(currentChar)) {
                while (ws <= we) {
                    if (counter.containsKey(s2.charAt(ws))) {
                        if (counter.get(s2.charAt(ws)) == 0) {
                            --matchedCount;
                        }
                        counter.put(s2.charAt(ws), counter.get(s2.charAt(ws))+1);
                    }
                    ws++;
                }
            } else {
                while (counter.get(currentChar) == 0) {
                    if (counter.containsKey(s2.charAt(ws))) {
                        if (counter.get(s2.charAt(ws)) == 0) {
                            --matchedCount;
                        }
                        counter.put(s2.charAt(ws), counter.get(s2.charAt(ws))+1);
                    }
                    ws++;
                }
                counter.put(currentChar, counter.get(currentChar)-1);
                if (counter.get(currentChar) == 0) {
                    matchedCount++;
                }
                if (matchedCount == counter.size()) return true;
            }
        }
        return false;
    }
}