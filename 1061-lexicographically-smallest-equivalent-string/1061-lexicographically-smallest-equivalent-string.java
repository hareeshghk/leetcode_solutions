class UnionFind {
    private int[] parents;
    public UnionFind() {
        parents = new int[26];
        for (int i = 0; i < 26; ++i) {
            parents[i] = i;
        }
    }

    public void unionObjects(int a, int  b) {
        a = find(a);
        b = find(b);

        if (a == b) {
            return;
        }

        if (a < b) {
            parents[b] = a;
        } else {
            parents[a] = b;
        }
    }

    public int find(int a) {
        if (parents[a] != a) {
            parents[a] = find(parents[a]);
        }
        return parents[a];
    }
}

class Solution {
    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        int num_chars = s1.length();

        UnionFind uf = new UnionFind();

        for (int i = 0; i < num_chars; ++i) {
            uf.unionObjects(s1.charAt(i)-'a', s2.charAt(i)-'a');    
        }

        String answer = new String("");

        for (char ch : baseStr.toCharArray()) {
            answer += (char)(uf.find(ch-'a') + 'a');
        }
        return answer;
    }
}