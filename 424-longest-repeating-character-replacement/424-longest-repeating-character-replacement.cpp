class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq_map(26, 0);
        int maxlen = 0;
        int ws = 0;
        for (int we = 0; we < s.length(); ++we) {
            freq_map[s[we]-'A']++;
            
            while (we-ws+1 - maxfreq(freq_map) > k) {
                freq_map[s[ws]-'A']--;
                ws++;
            }
            maxlen = max(maxlen, we-ws+1);
        }
        return maxlen;
    }
    
    int maxfreq(vector<int> &arr) {
        int result = arr[0];
        for (int i = 1; i < 26; i++) {
            result = max(result, arr[i]);
        }
        return result;
    }
};