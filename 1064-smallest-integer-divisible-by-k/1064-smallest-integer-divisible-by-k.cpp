class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int num = 1;
        int ans = 1;
        unordered_set<int> seen;
        while (num != 0) {
            while (num < k) {
                num = (num * 10) + 1;
                ans++;
            }

            num = num%k;
            if (seen.find(num) != seen.end()) return -1;
            seen.insert(num);
        }
        return ans;
    }
};