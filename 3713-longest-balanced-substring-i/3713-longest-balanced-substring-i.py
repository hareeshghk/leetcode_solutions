class Solution:
    def longestBalanced(self, s: str) -> int:
        n: int = len(s)
        res = 0

        for i in range(n):
            counter = defaultdict(int)
            for j in range(i, n):
                counter[s[j]]+=1
                if len(set(counter.values())) == 1:
                    res = max(res, j-i+1)
        return res
        