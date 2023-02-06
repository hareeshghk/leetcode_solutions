class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> answer = new ArrayList<>();

        if (s.length() < p.length()) return answer;

        HashMap<Character, Integer> store = new HashMap<>();

        for (char ch : p.toCharArray()) {
            store.put(ch, store.getOrDefault(ch, 0) + 1);
        }

        int matchCount = 0;

        int ws = 0, we = 0;

        for (we  = 0; we < s.length(); ++we) {
            if (we-ws+1 > p.length()) {
                if (store.containsKey(s.charAt(ws))) {
                    matchCount--;
                    store.put(s.charAt(ws), store.get(s.charAt(ws))+1);
                }
                ws++;
            }

            if (store.containsKey(s.charAt(we))) {
                while(store.get(s.charAt(we)) == 0) {
                    if (store.containsKey(s.charAt(ws))) {
                        matchCount--;
                        store.put(s.charAt(ws), store.get(s.charAt(ws))+1);
                    }
                    ws++;
                }

                matchCount++;
                store.put(s.charAt(we), store.get(s.charAt(we))-1);

                if(matchCount == p.length()) {
                    answer.add(ws);
                }
            } else {
                while (ws <= we) {
                    if (store.containsKey(s.charAt(ws))) {
                        matchCount--;
                        store.put(s.charAt(ws), store.get(s.charAt(ws))+1);
                    }
                    ws++;
                }
            }
        }
        return answer;
    }
}