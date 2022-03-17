class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        
        int diff1 = 0, diff2 = 0;
        if (n%2 == 0) {
            for (int i = 0; i < n; i++) {
                if (i&1) {
                    if (s[i] == '1') {
                        diff2++;
                    } else {
                        diff1++;
                    }
                } else {
                    if (s[i] == '1') {
                        diff1++;
                    } else {
                        diff2++;
                    }
                }
            }
            return min(diff1, diff2);
        }
        
        s = s+s;
        
        int ws = 0;
        int result = INT_MAX;
        for (int we = 0; we < s.length(); ++we) {
            if (we & 1) {
                if (s[we] == '1') {
                    diff2++;
                } else {
                    diff1++;
                }
            } else {
                if (s[we] == '1') {
                    diff1++;
                } else {
                    diff2++;
                }
            }
            
            if (we - ws + 1 == n) {
                result = min(result, min(diff1, diff2));
                if (result == 0) break;
                if (ws & 1) {
                    if (s[ws] == '1') {
                        diff2--;
                    } else {
                        diff1--;
                    }
                } else {
                    if (s[ws] == '1') {
                        diff1--;
                    } else {
                        diff2--;
                    }
                }
                ws++;
            }
        }
        return result;
    }
};