class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int a_count = 0, b_count = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') a_count++;
        }

        int ans = n;
        ans = min(ans, a_count + b_count);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') {
                a_count--;
            } else {
                b_count++;
            }
            ans = min(ans, a_count + b_count);
        }
        ans = min(ans, a_count + b_count);
        return ans;
    }
};